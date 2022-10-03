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
    int N;char c;cin>>N>>c;
    string S;cin>>S;
    bool f=true;
    for(char x:S) if(x!=c) f=false;
    if(f){
        cout<<0<<"\n";
        return;
    }else{
        for(int i=2;i<=N;i++){
            f=true;
            for(int j=i;j<=N;j+=i) if(S[j-1]!=c) f=false;
            if(f){
                cout<<1<<"\n";
                cout<<i<<"\n";
                return;
            }
        }
        cout<<2<<"\n";
        cout<<N-1<<" "<<N<<"\n";
        return;
    }
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