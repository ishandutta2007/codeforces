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
const int mod=998244353,MAX=500005;
const ll INF=1LL<<60;

vector<int> prime;//i
bool is_prime[MAX+1];
vector<int> fac[MAX];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            fac[i].push_back(i);
            for(int j=2*i;j<=n;j+=i){
                fac[j].push_back(i);
                is_prime[j] = false;
            }
        }
    }
}

ll cnt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    int N,Q;cin>>N>>Q;
    vector<int> A(N),deta(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll ans=0,sz=0;
    while(Q--){
        int i;cin>>i;i--;
        int x=A[i];
        if(!deta[i]){
            sz++;
            deta[i]=true;
            int M=si(fac[x]);
            for(int bit=1;bit<(1<<M);bit++){
                int seki=1;
                for(int j=0;j<M;j++){
                    if(bit&(1<<j)) seki*=fac[x][j];
                }
                if(__builtin_popcount(bit)&1) ans-=cnt[seki];
                else ans+=cnt[seki];
                cnt[seki]++;
            }
            cout<<sz*(sz-1)/2+ans<<"\n";
        }else{
            sz--;
            deta[i]=false;
            int M=si(fac[x]);
            for(int bit=1;bit<(1<<M);bit++){
                int seki=1;
                for(int j=0;j<M;j++){
                    if(bit&(1<<j)) seki*=fac[x][j];
                }
                cnt[seki]--;
                if(__builtin_popcount(bit)&1) ans+=cnt[seki];
                else ans-=cnt[seki];
            }
            cout<<sz*(sz-1)/2+ans<<"\n";
        }
    }
}