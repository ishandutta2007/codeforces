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

void solve(){
    string S;cin>>S;
    int ans=0,i=0;
    while(i<si(S)){
        if(S[i]=='1'){
            i++;
            continue;
        }
        ans++;
        while(i<si(S)&&S[i]=='0'){
            i++;
        }
        while(i<si(S)&&S[i]=='1'){
            i++;
        }
        if(i==si(S)){
            cout<<1<<"\n";
            return;
        }else{
            cout<<2<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}