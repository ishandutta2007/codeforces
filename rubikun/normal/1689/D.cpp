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
const int mod=998244353,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<pair<int,int>> X;
        for(int i=0;i<N;i++){
            string S;cin>>S;
            for(int j=0;j<M;j++){
                if(S[j]=='B'){
                    X.push_back(mp(i,j));
                }
            }
        }
        
        int a=-INF,b=-INF,c=-INF,d=-INF;
        for(auto x:X){
            chmax(a,-x.fi-x.se);
            chmax(b,-x.fi+x.se);
            chmax(c,x.fi-x.se);
            chmax(d,x.fi+x.se);
        }
        
        int ans=INF;
        pair<int,int> res=mp(-1,-1);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int ma=-1;
                int x=i,y=j;
                chmax(ma,a+x+y);
                chmax(ma,b+x-y);
                chmax(ma,c-x+y);
                chmax(ma,d-x-y);
                if(chmin(ans,ma)){
                    res=mp(i,j);
                }
            }
        }
        
        cout<<res.fi+1<<" "<<res.se+1<<"\n";
    }
}