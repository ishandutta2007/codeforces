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
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        string T;cin>>T;
        
        int N=si(S),M=si(T);
        
        bool ok=false;
        
        for(int i=0;i<N;i++){
            for(int j=0;i+j<N;j++){
                for(int k=0;i+j-k>=0;k++){
                    int len=1+j+k;
                    if(len!=M) continue;
                    string X;
                    for(int t=i;t<=i+j;t++) X+=S[t];
                    for(int t=i+j-1;t>=i+j-k;t--) X+=S[t];
                    if(X==T) ok=true;
                }
            }
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}