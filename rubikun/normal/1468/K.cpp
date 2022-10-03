#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define mp make_pair
#define fi first
#define se second
#define si(x) int(x.size())
const int INF=1<<30;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(nullptr)->sync_with_stdio(false);
    
    map<char,int> dx,dy;
    dx['L']=-1;
    dy['L']=0;
    
    dx['R']=1;
    dy['R']=0;
    
    dx['U']=0;
    dy['U']=1;
    
    dx['D']=0;
    dy['D']=-1;
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        pair<int,int> ans=mp(INF,INF);
        int N=si(S);
        
        for(int q=0;q<N;q++){
            pair<int,int> now=mp(0,0);
            for(int k=0;k<q;k++){
                now.fi+=dx[S[k]];
                now.se+=dy[S[k]];
            }
            auto ne=mp(now.fi+dx[S[q]],now.se+dy[S[q]]);
            if(ne.fi==0&&ne.se==0) continue;
            
            now=mp(0,0);
            for(int k=0;k<N;k++){
                auto to=mp(now.fi+dx[S[k]],now.se+dy[S[k]]);
                if(ne==to) continue;
                
                now=to;
            }
            
            if(now==mp(0,0)){
                ans=ne;
            }
        }
        
        if(ans.fi==INF){
            cout<<0<<" "<<0<<"\n";
        }else{
            cout<<ans.fi<<" "<<ans.se<<"\n";
        }
    }
}