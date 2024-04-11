#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1100005;
const ll INF=1LL<<60;
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
    
    ll N,M;cin>>N>>M;
    sieve(MAX-2);
    
    vector<pair<ll,int>> p;
    
    for(int a:prime){
        if(M%a==0){
            int cnt=0;
            while(M%a==0){
                M/=a;
                cnt++;
            }
            p.push_back({a,cnt});
        }
    }
    
    if(M>1) p.push_back({M,1});
    
    ll ans=INF;
    
    for(auto a:p){
        ll now=a.first;
        ll cnt=0;
        while(N>=now){
            cnt+=N/now;
            if(N/now/a.first) now*=a.first;
            else break;
        }
        ans=min(ans,cnt/a.second);
    }
    
    cout<<ans<<endl;
}