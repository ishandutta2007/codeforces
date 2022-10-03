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
        int ans=10;
        for(int bit=0;bit<(1<<10);bit++){
            string U;
            for(int i=0;i<10;i++){
                if(bit&(1<<i)) U+='1';
                else U+='0';
            }
            bool ok=true;
            for(int i=0;i<10;i++){
                if(S[i]!='?'){
                    if(S[i]!=U[i]) ok=false;
                }
            }
            if(!ok) continue;
            
            int a=0,b=0;
            for(int i=0;i<10;i++){
                if(U[i]=='1'){
                    if(i&1) b++;
                    else a++;
                }
                int ta=(9-i)/2,tb=(10-i)/2;
                if(a+ta<b) chmin(ans,i+1);
                if(b+tb<a) chmin(ans,i+1);
            }
        }
        
        cout<<ans<<"\n";
    }
}