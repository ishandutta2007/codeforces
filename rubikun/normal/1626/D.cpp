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
const int mod=998244353,MAX=500005,INF=1<<30;

int need[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int t=18;t>=0;t--){
        need[(1<<t)]=0;
        if(t==0) break;
        for(int i=(1<<t)-1;i>=(1<<(t-1));i--){
            need[i]=need[i+1]+1;
        }
    }
    need[0]=1;
    //for(int i=0;i<10;i++) cout<<need[i]<<endl;
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> cnt(N+2);
        for(int i=0;i<N;i++){
            int x;cin>>x;cnt[x]++;
        }
        for(int i=1;i<=N+1;i++) cnt[i]+=cnt[i-1];
        int ans=INF;
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<20;j++){
                int x=cnt[i]+(1<<j);
                auto it=upper_bound(all(cnt),x);it--;
                int a=cnt[i],b=(*it)-cnt[i],c=N-(*it);
                chmin(ans,need[a]+need[b]+need[c]);
            }
            chmin(ans,need[cnt[i]]+need[0]+need[N-cnt[i]]);
        }
        
        cout<<ans<<"\n";
    }
}