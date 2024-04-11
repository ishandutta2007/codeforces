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

bool pari[MAX];

vector<int> prime;//i
bool is_prime[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            pari[i]^=1;
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
                pari[j]^=1;
            }
        }
    }
}

bool f[MAX];

vector<int> yaku[MAX];

ll imo[2000005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    for(int i=1;i<=200000;i++){
        for(int j=i*2;j<=200000;j+=i) yaku[j].push_back(i);
    }
    int N;cin>>N;
    vector<ll> A(N+1),B(N+1);
    for(int i=0;i<N;i++) cin>>A[i+1];
    for(int i=0;i<N;i++) cin>>B[i+1];
    for(int i=1;i<=N;i++){
        f[i]=true;
        for(int p:prime){
            if(p*p>i) break;
            if(i%(p*p)==0) f[i]=false;
            if(!f[i]) break;
        }
    }
    //pari true == -(b1-a1)
    
    B[1]=0;
    
    ll ans=0;
    vector<ll> cnt(N+1);
    for(int i=1;i<=N;i++){
        ll now=A[i];
        for(int a:yaku[i]){
            now+=cnt[a];
        }
        cnt[i]=B[i]-now;
        ans+=abs(cnt[i]);
    }
    
    for(int i=1;i<=N;i++){
        if(!f[i]) continue;
        if(pari[i]){
            if(cnt[i]<=0){
                imo[1]++;
            }else{
                imo[1]--;
                chmin(cnt[i],1000005LL);
                imo[cnt[i]+1]++;
                imo[cnt[i]+1]++;
            }
        }else{
            if(cnt[i]>=0){
                imo[1]++;
            }else{
                imo[1]--;
                cnt[i]*=(-1);
                chmin(cnt[i],1000005LL);
                imo[cnt[i]+1]++;
                imo[cnt[i]+1]++;
            }
        }
    }
    
    for(int i=2;i<=1000006;i++) imo[i]+=imo[i-1];
    for(int i=2;i<=1000006;i++) imo[i]+=imo[i-1];
    
    int Q;cin>>Q;
    while(Q--){
        int x;cin>>x;
        cout<<ans+imo[x]<<"\n";
    }
}