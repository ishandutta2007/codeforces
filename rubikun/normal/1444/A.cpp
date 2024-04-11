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
const int mod=1000000007,MAX=100005,INF=1<<30;

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
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    
    int Q;cin>>Q;
    
    while(Q--){
        ll p,q;cin>>p>>q;
        if(p%q){
            cout<<p<<"\n";
        }else{
            vector<int> cnt1(si(prime)),cnt2(si(prime));
            ll sp=p,sq=q;
            for(int i=0;i<si(prime);i++){
                while(p%prime[i]==0){
                    cnt1[i]++;
                    p/=prime[i];
                }
                while(q%prime[i]==0){
                    cnt2[i]++;
                    q/=prime[i];
                }
            }
            ll ans=0;
            if(q>1){
                p=sp;
                while(p%q==0) p/=q;
                chmax(ans,p);
            }
            for(int i=0;i<si(prime);i++){
                if(cnt2[i]){
                    int diff=cnt1[i]-(cnt2[i]-1);
                    p=sp;
                    while(diff--) p/=prime[i];
                    
                    chmax(ans,p);
                }
            }
            
            cout<<ans<<"\n";
        }
    }
}