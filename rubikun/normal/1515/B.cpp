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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    set<int> SE;
    
    for(int i=1;i*i<=1000000000;i++){
        SE.insert(i*i);
    }
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        bool ok=false;
        
        if(N%2==0&&SE.count(N/2)) ok=true;
        if(N%4==0&&SE.count(N/4)) ok=true;
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}