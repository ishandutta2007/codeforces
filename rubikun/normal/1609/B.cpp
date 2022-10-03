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
    
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    int ans=0;
    for(int i=0;i+2<N;i++){
        if(S[i]=='a'&&S[i+1]=='b'&&S[i+2]=='c') ans++;
    }
    while(Q--){
        int p;char c;cin>>p>>c;
        p--;
        for(int i=p-2;i<=p;i++){
            if(i<0||i+2>=N) continue;
            if(S[i]=='a'&&S[i+1]=='b'&&S[i+2]=='c') ans--;
        }
        S[p]=c;
        for(int i=p-2;i<=p;i++){
            if(i<0||i+2>=N) continue;
            if(S[i]=='a'&&S[i+1]=='b'&&S[i+2]=='c') ans++;
        }
        
        cout<<ans<<"\n";
    }
}