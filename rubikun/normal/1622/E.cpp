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
const int mod=998244353,MAX=5005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<ll> x(N);
        for(int i=0;i<N;i++) cin>>x[i];
        pair<ll,vector<ll>> ans=mp(-1,vector<ll>());
        
        vector<string> S(N);
        for(int i=0;i<N;i++){
            cin>>S[i];
        }
        
        for(int bit=0;bit<(1<<N);bit++){
            ll sum=0;
            for(int i=0;i<N;i++){
                if(bit&(1<<i)) sum-=x[i];
                else sum+=x[i];
            }
            
            vector<ll> id(M),score(M);
            iota(all(id),0);
            for(int T=0;T<M;T++){
                for(int i=0;i<N;i++){
                    if(S[i][T]=='1'){
                        if(bit&(1<<i)) score[T]++;
                        else score[T]--;
                    }
                }
            }
            
            sort(all(id),[&](int a,int b){
                return score[a]>score[b];
            });
            
            for(int T=0;T<M;T++){
                sum+=score[id[T]]*(M-T);
            }
            
            chmax(ans,mp(sum,id));
        }
        
        vector<int> P(M);
        for(int j=0;j<si(ans.se);j++) P[ans.se[j]]=M-j;
        for(int a:P) cout<<a<<" ";
        cout<<"\n";
    }
}