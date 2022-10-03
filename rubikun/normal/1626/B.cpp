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
const int mod=998244353,MAX=5005,INF=1<<30;

void solve(){
    string S;cin>>S;
    int N=si(S);
    for(int i=N-2;i>=0;i--){
        int a=(int)(S[i]-'0'),b=(int)(S[i+1]-'0');
        if(a+b>=10){
            cout<<S.substr(0,i);
            cout<<a+b;
            cout<<S.substr(i+2);
            cout<<"\n";
            return;
        }
    }
    int a=(int)(S[0]-'0'),b=(int)(S[1]-'0');
    cout<<a+b;
    cout<<S.substr(2);
    cout<<"\n";
    return;
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}