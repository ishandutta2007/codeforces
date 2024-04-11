// 3:16

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int N = 50002;
int n,x; LL T;
struct Task {
    int t,s,p,tp,id;
    bool operator<(const Task&o)const{
        if(p==o.p) return tp<o.tp;
        return p<o.p;
    }
    void P() {
        printf("t=%d, s=%d, p=%d\n", t,s,p);
    }
} task[N],ta[N];
bool cmp(Task a,Task b){
    return a.t < b.t;
}
map<int,int> mp;
const LL inf = 1e18;
LL ans[N];
LL cac(int val) {
    for(int i=1;i<=n;i++) ta[i]=task[i];
    ta[x].p = val;
    sort(ta+1,ta+1+n,cmp);

    priority_queue<Task> q;
    for(int i=1,j=1;i<=n;i=j) {
        while(j<=n && ta[j].t == ta[i].t) {
            //ta[j].P();
            q.push(ta[j++]); 
        }
        LL gap = ((j==n+1) ? inf : ta[j].t) - ta[i].t;

        LL tmpsum = 0;
        while(q.size() && gap) {
            Task tmp = q.top();
            tmpsum += min((LL)tmp.s, gap);
            if (tmp.s <= gap) {
                gap -= tmp.s; q.pop(); ans[tmp.id] = ta[i].t + tmpsum;  
            } else {
                tmp.s -= gap; gap=0; q.pop(); q.push(tmp);
            }
        }

    }
    return ans[x];
}


int main() {
      freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",&task[i].t,&task[i].s,&task[i].p); task[i].tp=0; task[i].id=i;
        if(task[i].p==-1) x=i;
        mp[task[i].p]=1;
    }
    
    scanf("%lld",&T); task[x].tp=1;
    
    int lef=0,rig=1000000001;
    while(rig-lef>1){
        int mid=(lef+rig)>>1;
        if(cac(mid) <= T) rig = mid;
        else lef = mid;
    }
    while(mp[rig]) ++rig;
    
    cac(rig);
    printf("%d\n", rig);
    for(int i=1;i<=n;i++) printf("%lld ", ans[i]);
}