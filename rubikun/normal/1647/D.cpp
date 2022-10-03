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
const int mod=998244353,MAX=50005,INF=1<<30;

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
    
    sieve(MAX-3);
    
    int Q;cin>>Q;
    while(Q--){
        ll X,D;cin>>X>>D;
        ll cn=0;
        while(X%D==0){
            X/=D;
            cn++;
        }
        if(cn<=1){
            cout<<"NO\n";
            continue;
        }
        
        ll rem=X*D;
        
        int wa=0;
        for(int p:prime){
            while(X%p==0){
                wa++;
                X/=p;
            }
        }
        if(X>1) wa++;
        
        if(wa>=2){
            cout<<"YES\n";
            continue;
        }
        if(cn==2){
            cout<<"NO\n";
            continue;
        }
        
        cn--;
        
        //cout<<rem<<" "<<cn<<" ";
        
        vector<ll> yaku;
        for(ll i=1;i*i<=rem;i++){
            if(rem%i==0){
                yaku.push_back(i);
                if(i*i!=rem) yaku.push_back(rem/i);
            }
        }
        sort(all(yaku));
        
        vector<ll> waru;
        for(ll a:yaku) if(a%D) waru.push_back(a);
        
        map<int,int> dis;
        queue<int> QQ;
        dis[rem]=0;QQ.push(rem);
        while(!QQ.empty()){
            int u=QQ.front();QQ.pop();
            if(dis[u]==cn) break;
            for(int to:waru){
                if(u%to==0&&!dis.count(u/to)){
                    dis[u/to]=dis[u]+1;
                    QQ.push(u/to);
                }
            }
        }
        //cout<<dis[1]<<" ";
        if(dis.count(1)&&dis[1]<=cn) cout<<"YES\n";
        else cout<<"NO\n";
    }
}