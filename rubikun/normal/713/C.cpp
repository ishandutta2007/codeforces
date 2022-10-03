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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    priority_queue<ll> L;
    priority_queue<ll,vector<ll>,greater<ll>> R;
    
    ll mi=0;
    
    L.push(-INF);
    R.push(INF);
    
    for(int i=0;i<N;i++){
        while(!R.empty()) R.pop();
        
        ll l0=L.top();
        ll x;cin>>x;x-=i;
        mi+=max(0LL,l0-x);
        L.push(x);
        ll y=L.top();L.pop();R.push(y);
        
        ll r0=R.top();
        mi+=max(0LL,x-r0);
        R.push(x);
        ll z=R.top();R.pop();L.push(z);
    }
    
    cout<<mi<<endl;
}