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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    bool aru=false;
    for(int i=0;i<N;i++) if(A[i]==1) aru=true;
    
    if(aru){
        int ans=0;
        for(int i=0;i<N;i++) if(A[i]!=1) ans++;
        cout<<ans<<endl;
        return 0;
    }
    
    int need=INF;
    for(int i=0;i<N;i++){
        ll g=0;
        for(int j=i;j<N;j++){
            g=gcd(g,A[j]);
            if(g==1){
                chmin(need,j-i+1);
                break;
            }
        }
    }
    
    if(need==INF) cout<<-1<<endl;
    else cout<<need-1+N-1<<endl;
}