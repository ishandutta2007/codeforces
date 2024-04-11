#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100000+10;
int a[N],n,b[N];

struct op {
    int l,mid,r;
} pre[1<<12];
vector<op> ans,tmp;
void brute(){
    int mx=min(10,n);
    int mask=0;
    for(int i=0;i<mx;i++){
        if(a[i])mask|=1<<i;      
    }
    int vis[1<<12]={0};
    queue<int> q; q.push(mask);vis[mask]=1;
    while(q.size()){
        int u=q.front();q.pop();
        for(int mid=1;mid<mx;mid++){
            for(int d=1;d<mx;d++){
                int l=mid-d, r=mid+d;
                if(l<0||r>=mx)continue;
                int bu=1<<l|1<<r|1<<mid;
                if(vis[u^bu]==0){
                    vis[u^bu]=1; q.push(u^bu);
                    pre[u^bu]=(op){l,mid,r};
                }
            }
        }
    }
    int now = 0; if(vis[now]==0) {
        printf("NO\n"); exit(0);
    }
    while(now!=mask) {
        op o = pre[now]; tmp.push_back(o);
        int bu=1<<o.l|1<<o.r|1<<o.mid;
        now ^= bu;
        //printf("now = %d\n", now);
    }
    reverse(tmp.begin(),tmp.end());
    for(auto o: tmp) {
        ans.push_back(o);
    }
}

vector<op> vec[1<<6];
void solve(int mask) {
    if(mask==0) return;
    int tot = (1<<6)-1;
    for(int l=0;l<6;l++){
        for(int mid=l+1;mid<=6;mid++){
            int r=2*mid-l; if(r>=11)continue;
            int nex = mask^(1<<l|1<<mid|1<<r);
            if((nex&tot)==0) {
                vec[mask].push_back((op){l,mid,r}); return;
            }
        }
    }
    for(int l=0;l<6;l++){
        for(int mid=l+1;mid<=6;mid++){
            for(int l_=0;l_<6;l_++){
                for(int mid_=l_+1;mid_<=6;mid_++){
                    int r=2*mid-l;
                    int r_=2*mid_-l_;if(r>=11||r_>=11)continue;
                    int nex = mask^(1<<l|1<<mid|1<<r);
                    nex ^= (1<<l_|1<<mid_|1<<r_);

                    if((nex&tot)==0) {
                        vec[mask].push_back((op){l,mid,r});
                        vec[mask].push_back((op){l_,mid_,r_});
                        return;
                    }
                }
            }
        }
    }
    //printf("bu = %d\n", mask);
}
void init() {
    for(int i=0;i<1<<6;i++) {
        solve(i);     
    }
}

int main() {
    init();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        //a[i]=rand()%2;
        //printf("%d ", a[i]);
        b[i]=a[i];
    } //printf("\n");
    for(int i=n-1;i>=10;i-=6) {
        int mask=0;
        for(int j=i;j>i-6;j--){
            if(a[j]) mask|=(1<<(i-j));
        }
        for(auto o: vec[mask]) {
            int r = i-o.l;
            int mid = i-o.mid;
            int l = i-o.r;
            a[l]^=1, a[mid]^=1, a[r]^=1;
            ans.push_back((op){l,mid,r});
            //printf("l=%d, mid=%d, r=%d\n", l+1,mid+1,r+1);
        }
    }
    brute();
    printf("YES\n");
    printf("%d\n", ans.size());
    for(auto o: ans) {
        b[o.l]^=1, b[o.mid]^=1, b[o.r]^=1;
        printf("%d %d %d\n", o.l+1,o.mid+1,o.r+1);
    }
    //for(int i=0;i<n;i++) printf("%d ", b[i]);
}
// ......#......