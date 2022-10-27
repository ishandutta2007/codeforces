#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1002;
int n,k;
struct Item{
    int c,t,id;
    bool operator< (const Item &o)const{
        return c>o.c;
    }
} p[N];
vector<Item> v; int vis[N];

int main(){
    scanf("%d%d",&n,&k); LL ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].c,&p[i].t); p[i].id=i;
        ans += p[i].c;
        if(p[i].t==1) v.push_back(p[i]);
    }
    sort(v.begin(),v.end());

    if(k > v.size()) {
        LL sum=0;
        for(int i=0;i<v.size();i++) {
            sum += v[i].c; 
        }
        printf("%.1f\n", ans-sum/2.0);

        for(int i=0;i<v.size();i++) {
            printf("1 %d\n", v[i].id); vis[v[i].id] = 1;
        }

        int group=v.size();
        for(int i=1;i<=n;i++) {
            if(p[i].t == 2) {
                if(group == k-1) break;
                printf("1 %d\n", i); vis[i]=1; group ++;
            }
        }
        int cnt=0; for(int i=1;i<=n;i++) if(vis[i]==0)cnt++;
        printf("%d ", cnt); for(int i=1;i<=n;i++) if(vis[i]==0) printf("%d ",i);

    } else {
        LL sum=0;
        for(int i=0;i<k-1;i++) {
            sum += v[i].c; vis[v[i].id] = 1;
        }
        LL mn=1e12;
        for(int i=1;i<=n;i++) {
            if(vis[i]==0)mn=min(mn,(LL)p[i].c);
        }
        sum+=mn;
        printf("%.1f\n", ans-sum/2.0);
        for(int i=0;i<k-1;i++) {
            printf("1 %d\n", v[i].id);
        }        
        int cnt=0; for(int i=1;i<=n;i++) if(vis[i]==0)cnt++;
        printf("%d ", cnt); for(int i=1;i<=n;i++) if(vis[i]==0) printf("%d ",i);
    }

}