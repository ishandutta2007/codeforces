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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        int mih=100,miw=100;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]=='R'){
                    chmin(mih,i);
                    chmin(miw,j);
                }
            }
        }
        
        if(S[mih][miw]=='R'){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}