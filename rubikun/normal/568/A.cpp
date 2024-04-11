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

const int mod=1000000007,MAX=2000005,INF=1<<30;

vector<int> prime;//i
ll is_prime[MAX+1],pari[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
        
        if(i==0) continue;
        string x=to_string(i),y=x;
        reverse(all(y));
        if(x==y) pari[i]=pari[i-1]+1;
        else pari[i]=pari[i-1];
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
    
    sieve(2000000);
    
    int ans=0;
    
    ll p,q;cin>>p>>q;
    
    for(int i=1;i<=2000000;i++){
        is_prime[i]+=is_prime[i-1];
        
        if(is_prime[i]*q<=pari[i]*p) ans=i;
    }
    
    cout<<ans<<endl;
        
}