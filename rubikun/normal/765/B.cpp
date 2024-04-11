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
const int mod=1000000007,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    vector<int> wh(26,INF);
    for(int i=0;i<si(S);i++){
        chmin(wh[int(S[i]-'a')],i);
    }
    bool ok=true;
    for(int i=0;i<25;i++) if(wh[i]>wh[i+1]) ok=false;
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}