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

vector<pair<int,int>> HQ[MAX],WQ[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,W,H;cin>>N>>W>>H;
    for(int i=0;i<N;i++){
        int g,p,t;cin>>g>>p>>t;
        p+=100000;
        if(g==1) WQ[p-t].push_back(mp(p-100000,i));
        else HQ[p-t].push_back(mp(p-100000,i));
    }
    
    vector<pair<int,int>> ans(N);
    
    for(int po=200000;po>=0;po--){
        sort(all(WQ[po]));
        sort(all(HQ[po]));
        reverse(all(HQ[po]));
        
        if(si(HQ[po])==0){
            for(auto a:WQ[po]){
                ans[a.se]=mp(H,a.fi);
            }
        }else{
            if(si(WQ[po])==0){
                for(auto a:HQ[po]){
                    ans[a.se]=mp(a.fi,W);
                }
            }else{
                vector<pair<int,int>> G;
                for(auto a:WQ[po]) G.push_back(mp(H,a.fi));
                for(auto a:HQ[po]) G.push_back(mp(a.fi,W));
                
                int t=0;
                for(auto a:HQ[po]){
                    ans[a.se]=G[t];
                    t++;
                }
                for(auto a:WQ[po]){
                    ans[a.se]=G[t];
                    t++;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i].se<<" "<<ans[i].fi<<"\n";
}