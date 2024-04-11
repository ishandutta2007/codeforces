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

//using mint=atcoder::modint998244353;
//using mint=atcoder::modint1000000007;

struct dat{
    ll i;
    ll j;
    ll x;
};

vector<dat> ans;

void f(ll i,ll j,ll x,vector<ll> &A){
    ans.push_back({i,j,x});
    A[i]-=i*x;
    A[j]+=i*x;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        ans.clear();
        vector<ll> A(N+1);
        ll sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i+1];
            sum+=A[i+1];
        }
        
        if(sum%N){
            cout<<-1<<"\n";
            continue;
        }
        
        sum/=N;
        
        for(int i=2;i<=N;i++){
            ll x;
            if(A[i]%i==0) x=0;
            else x=i-A[i]%i;
            
            f(1,i,x,A);
            
            ll y=A[i]/i;
            
            f(i,1,y,A);
        }
        
        for(int i=2;i<=N;i++){
            f(1,i,sum,A);
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans) cout<<a.i<<" "<<a.j<<" "<<a.x<<"\n";
    }
}