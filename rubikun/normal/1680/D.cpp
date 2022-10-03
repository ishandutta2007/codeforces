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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q=1;
    while(Q--){
        ll N,K;cin>>N>>K;
        vector<ll> A(N);
        ll sum=0,zero=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=A[i];
            if(A[i]==0) zero++;
        }
        if(-K*zero<=sum&&sum<=K*zero){
            ll ans=1;
            if(zero==0){
                ll ma=0,mi=0,now=0;
                for(int i=0;i<N;i++){
                    now+=A[i];
                    chmax(ma,now);
                    chmin(mi,now);
                }
                chmax(ans,ma-mi+1);
                cout<<ans<<"\n";
                continue;
            }
            for(ll a=0;a<zero;a++){
                ll b=zero-1-a;
                ll al=sum+a*K-b*K;
                if(abs(al)>K) continue;
                vector<ll> use;
                for(int i=0;i<a;i++) use.push_back(K);
                for(int i=0;i<b;i++) use.push_back(-K);
                use.push_back(-al);
                sort(all(use));
                
                for(int q=0;q<2;q++){
                    for(int i=0;i<=zero;i++){
                        vector<ll> B=A;
                        int cn=0;
                        for(int j=0;j<N;j++){
                            if(B[j]==0){
                                if(cn<i) B[j]=use[cn];
                                else B[j]=use[si(use)-1-(cn-i)];
                                cn++;
                            }
                        }
                        ll ma=0,mi=0,now=0;
                        for(int i=0;i<N;i++){
                            now+=B[i];
                            chmax(ma,now);
                            chmin(mi,now);
                        }
                        chmax(ans,ma-mi+1);
                    }
                    reverse(all(use));
                }
            }
            
            cout<<ans<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}