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
const int mod=1000000007,MAX=200005;
const ll INF=1<<30;
int N;
vector<ll> A,sum;
set<ll> SE;

void solve(int l,int r){
    if(l==r) return;
    
    ll a=A[l],b=A[r-1];
    SE.insert(sum[r]-sum[l]);
    
    if(a==b) return;
    
    ll c=(a+b)/2;
    
    auto it=upper_bound(all(A),c);
    
    solve(l,it-A.begin());
    solve(it-A.begin(),r);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int Q;cin>>N>>Q;
        A.resize(N);
        sum.resize(N+1);
        SE.clear();
        
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        sort(all(A));
        for(int i=1;i<=N;i++) sum[i]=sum[i-1]+A[i-1];
        
        solve(0,N);
        
        while(Q--){
            ll x;cin>>x;
            if(SE.count(x)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}