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
    
    int N,K;cin>>N>>K;
    vector<int> S(1<<K);
    for(int i=0;i<N;i++){
        int x=0;
        for(int j=0;j<K;j++){
            int a;cin>>a;
            x*=2;
            x+=a;
        }
        S[x]++;
    }
    
    bool ok=false;
    
    if(S[0]) ok=true;
    
    for(int i=1;i<(1<<K);i++){
        for(int j=1;j<(1<<K);j++){
            if(S[i]&&S[j]&&((i&j)==0)) ok=true;
        }
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}