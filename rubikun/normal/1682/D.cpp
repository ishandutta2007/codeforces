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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        vector<int> pa;
        for(int i=0;i<N;i++){
            if(S[i]=='1') pa.push_back(i);
        }
        if(si(pa)==0||(si(pa)&1)){
            cout<<"NO\n";
            continue;
        }
        
        vector<pair<int,int>> ans;
        for(int i=1;i<si(pa)-1;i++){
            int la=pa[0];
            for(int j=pa[i-1]+1;j<=pa[i];j++){
                ans.push_back(mp(la,j));
                la=j;
            }
        }
        int la=pa[0];
        for(int j=pa[si(pa)-2]+1;j<pa[si(pa)-1];j++){
            ans.push_back(mp(la,j));
            la=j;
        }
        for(int i=pa[0]-1;;i--){
            ans.push_back(mp(la,(i+N)%N));
            la=(i+N)%N;
            if((i+N)%N==pa[si(pa)-1]) break;
        }
        cout<<"YES\n";
        for(auto e:ans) cout<<e.fi+1<<" "<<e.se+1<<"\n";
    }
}