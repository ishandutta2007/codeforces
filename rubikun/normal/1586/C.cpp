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
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    vector<int> ng(W+1);
    for(int j=0;j+1<W;j++){
        for(int i=0;i+1<H;i++){
            if(S[i][j+1]=='X'&&S[i+1][j]=='X') ng[j+1]=1;
        }
    }
    for(int j=1;j<=W;j++) ng[j]+=ng[j-1];
    
    int Q;cin>>Q;
    while(Q--){
        int l,r;cin>>l>>r;
        l--;
        if(r-l==1) cout<<"YES\n";
        else{
            int x=ng[r-1]-ng[l];
            if(x) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}