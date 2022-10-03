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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime;//i
bool is_prime[MAX+1];
ll ha[MAX];
ll fac[MAX];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
        ha[i]=(ll)(rng()%INF)*INF+(ll)(rng()%INF);
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
            for(ll k=i;k<=n;k*=i){
                for(ll j=k;j<=n;j+=k){
                    fac[j]^=ha[i];
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++) fac[i]^=fac[i-1];
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-3);
    
    pair<int,vector<int>> ans;
    int N;cin>>N;
    ll rui=0;
    for(int i=1;i<=N;i++) rui^=fac[i];
    if(N%2==0){
        if((fac[N/2]^fac[2])==rui){
            ans=mp(2,vector<int>{N/2,2});
        }else{
            ans=mp(1,vector<int>{N/2});
        }
    }else{
        if((fac[N/2]^fac[2]^fac[N])==rui){
            ans=mp(3,vector<int>{N/2,2,N});
        }else{
            ans=mp(2,vector<int>{N/2,N});
        }
    }
    
    const ll D=1LL<<60;
    
    unordered_map<ll,ll> MA;
    for(int i=1;i<=N;i++){
        if(MA[fac[i]]>=(D*2)) continue;
        if(MA[fac[i]]>=D){
            MA[fac[i]]+=((ll)(i)<<30)+D;
        }else{
            MA[fac[i]]+=i+D;
        }
    }
    
    if(rui==0){
        cout<<N<<endl;
        for(int i=1;i<=N;i++) cout<<i<<" ";
        cout<<"\n";
        return 0;
    }
    for(int i=1;i<=N;i++){
        if(fac[i]==rui){
            cout<<N-1<<endl;
            for(int j=1;j<=N;j++) if(i!=j) cout<<j<<" ";
            cout<<"\n";
            return 0;
        }
    }
    
    for(int i=1;i<=N;i++){
        ll need=rui^fac[i];
        if(MA.count(need)){
            ll a=MA[need]&((1LL<<30)-1);
            
            if(a!=i){
                cout<<N-2<<endl;
                for(int j=1;j<=N;j++) if(i!=j&&a!=j) cout<<j<<" ";
                cout<<"\n";
                return 0;
            }else if(MA[need]&(1LL<<61)){
                ll b=(MA[need]>>30)&((1LL<<30)-1);
                if(b!=i){
                    cout<<N-2<<endl;
                    for(int j=1;j<=N;j++) if(i!=j&&b!=j) cout<<j<<" ";
                    cout<<"\n";
                    return 0;
                }
            }
        }
    }
    
    cout<<N-ans.fi<<"\n";
    for(int i=1;i<=N;i++){
        bool ok=true;
        for(int j=0;j<si(ans.se);j++) if(i==ans.se[j]) ok=false;
        if(ok) cout<<i<<" ";
    }
    cout<<"\n";
}