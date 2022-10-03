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
        ll H,W,X,Y;cin>>H>>W>>X>>Y;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        
        ll ans=0;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]=='*') continue;
                if(S[i][j]=='.'){
                    if(j+1<W&&S[i][j+1]=='.'){
                        ans+=min(2*X,Y);
                        j++;
                    }else{
                        ans+=X;
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
        
    }
}