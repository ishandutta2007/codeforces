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
const int mod=1000000007,MAX=500005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> C(N*K),cnt(N*K);
    vector<pair<int,int>> ans(N,mp(-1,-1));
    for(int i=0;i<N*K;i++){
        cin>>C[i];
        C[i]--;
    }
    int lim=(N+K-2)/(K-1);
    for(int r=0;r<N*K;r++){
        if(ans[C[r]].fi!=-1) continue;
        
        for(int l=r-1;l>=0;l--){
            if(C[l]==C[r]){
                bool ok=true;
                for(int k=l;k<=r;k++) if(cnt[k]+1>lim) ok=false;
                if(ok){
                    ans[C[r]]=mp(l,r);
                    for(int k=l;k<=r;k++) cnt[k]++;
                }
                break;
            }
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i].fi+1<<" "<<ans[i].se+1<<"\n";
}