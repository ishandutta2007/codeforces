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
const int mod=998244353,MAX=3005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    set<string> SE;
    for(int i=0;i<2;i++){
        string S;cin>>S;
        SE.insert(S);
    }
    
    for(auto a:SE) cout<<a<<" ";
    cout<<endl;
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        string A;cin>>A;
        SE.erase(A);
        string B;cin>>B;
        SE.insert(B);
        
        for(auto a:SE) cout<<a<<" ";
        cout<<endl;
    }
}