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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,M;cin>>N>>M;
        vector<pair<ll,ll>> S(M);
        vector<ll> sum(M);
        for(int i=0;i<M;i++){
            cin>>S[i].fi>>S[i].se;
        }
        sort(all(S),[](auto a,auto b){
            return a.fi>b.fi;
        });
        sum[0]=S[0].fi;
        for(int i=1;i<M;i++) sum[i]=sum[i-1]+S[i].fi;
        
        ll ans=0;
        for(int i=0;i<M;i++){
            ll get=0;
            int left=-1,right=min(N,M);
            while(right-left>1){
                int mid=(left+right)/2;
                if(S[mid].fi>=S[i].se) left=mid;
                else right=mid;
            }
            int id=left;
            if(id>=0) get+=sum[id];
            ll rem=N;
            rem-=(id+1);
            
            if(id<i){
                get+=S[i].fi;
                rem--;
            }
            
            if(rem<0){
                rem=0;
                get-=S[id].fi;
            }
            
            get+=rem*S[i].se;
            
            chmax(ans,get);
        }
        cout<<ans<<"\n";
    }
}