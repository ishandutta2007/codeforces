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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<char,int> MA;
    map<char,int> ne;
    string T="Bulbasaur";
    for(char c:T) ne[c]++;
    
    string S;cin>>S;
    for(char c:S) MA[c]++;
    int ans=INF;
    
    for(char c:T){
        chmin(ans,MA[c]/ne[c]);
    }
    
    cout<<ans<<endl;
}