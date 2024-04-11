#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

map<int,int> dp;
int need=-1;

int ask(int x){
    if(x<=0) return 0;
    if(x<need) return 0;
    if(dp.count(x)) return dp[x];
    cout<<"? "<<x<<endl;
    int y;cin>>y;
    return dp[x]=y;
}

int main(){
    
    int N;cin>>N;
    int left=N+N-1-1,right=2000*N+N-1;
    while(right-left>1){
        int mid=(left+right)/2;
        int res=ask(mid);
        if(res==1) right=mid;
        else left=mid;
    }
    
    need=(right-(N-1)+N-1)/N;
    
    int ans=right;
    
    for(int i=2;i<=N;){
        while(1){
            int x=(ans-1)/i;
            int res=ask(x);
            if(res&&res<=i) ans=x*res;
            else{
                if(res==0){
                    cout<<"! "<<ans<<endl;
                    return 0;
                }else{
                    i=res;
                    break;
                }
            }
        }
    }
    
    cout<<"! "<<ans<<endl;
}