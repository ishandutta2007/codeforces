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
const int mod=998244353,MAX=1000005,INF=1<<30;

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
                is_prime[j] = false;
                fac[j].push_back(i);
            }
        }
    }
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

bool deta[21000000];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-3);
    
    ll H,W;cin>>H>>W;
    
    vector<ll> cnt(100);
    
    for(int i=2;i<=H;i++){
        ll g=0;
        int now=i;
        for(int p:fac[i]){
            int cn=0;
            while(now%p==0){
                cn++;
                now/=p;
            }
            g=gcd(g,cn);
        }
        if(g==1){
            ll X=1;
            int cn=0;
            while(X*i<=H){
                X*=i;
                cn++;
            }
            cnt[cn]++;
        }
    }
    
    ll ans=1;
    ll syu=0;
    
    for(int t=1;t<=20;t++){
        for(int j=1;j<=W;j++){
            if(!deta[t*j]){
                deta[t*j]=true;
                syu++;
            }
        }
        ans+=syu*cnt[t];
    }
    
    cout<<ans<<"\n";
}