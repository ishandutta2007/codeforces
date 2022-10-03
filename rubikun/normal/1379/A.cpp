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
    string U="abacaba";
    while(Q--){
        int N;cin>>N;
        string S,T,res;cin>>S;
        T=S;
        for(int i=0;i+6<N;i++){
            S=T;
            bool ok=true;
            for(int j=0;j<7;j++){
                if(S[i+j]=='?') S[i+j]=U[j];
                else if(S[i+j]!=U[j]) ok=false;
            }
            if(!ok) continue;
            for(int j=0;j<N;j++) if(S[j]=='?') S[j]='z';
            
            int cnt=0;
            for(int j=0;j+6<N;j++){
                string X=S.substr(j,7);
                if(U==X) cnt++;
            }
            if(cnt==1){
                res=S;
                break;
            }
        }
        
        if(si(res)){
            cout<<"YES\n";
            cout<<res<<"\n";
        }else cout<<"NO\n";
    }
}