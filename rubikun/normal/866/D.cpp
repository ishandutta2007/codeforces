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
const int mod=1000000007,MAX=5205;
const ll INF=1LL<<50;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    priority_queue<ll,vector<ll>,greater<ll>> SE;
    ll now=0;
    
    for(int i=0;i<N;i++){
        ll a;cin>>a;
        SE.push(a);
        if(SE.top()<a){
            now+=(a-SE.top());
            SE.pop();
            SE.push(a);
        }
    }
    
    cout<<now<<endl;
    
}