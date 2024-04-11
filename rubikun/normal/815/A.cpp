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
    vector<vector<int>> S(H,vector<int>(W));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    
    vector<int> ans;
    
    if(H<=W){
        for(int i=0;i<H;i++){
            int mi=INF;
            for(int j=0;j<W;j++){
                chmin(mi,S[i][j]);
            }
            for(int k=0;k<mi;k++) ans.push_back(i+1);
            for(int j=0;j<W;j++) S[i][j]-=mi;
        }
        
        for(int j=0;j<W;j++){
            int mi=INF;
            for(int i=0;i<H;i++){
                chmin(mi,S[i][j]);
            }
            for(int k=0;k<mi;k++) ans.push_back(-(j+1));
            for(int i=0;i<H;i++) S[i][j]-=mi;
        }
        
        bool ok=true;
        
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(S[i][j]) ok=false;
        
        if(ok){
            cout<<si(ans)<<endl;
            for(int a:ans){
                if(a>=0) cout<<"row "<<a<<"\n";
                else cout<<"col "<<-a<<"\n";
            }
        }else cout<<-1<<endl;
    }else{
        for(int j=0;j<W;j++){
            int mi=INF;
            for(int i=0;i<H;i++){
                chmin(mi,S[i][j]);
            }
            for(int k=0;k<mi;k++) ans.push_back(-(j+1));
            for(int i=0;i<H;i++) S[i][j]-=mi;
        }
        
        for(int i=0;i<H;i++){
            int mi=INF;
            for(int j=0;j<W;j++){
                chmin(mi,S[i][j]);
            }
            for(int k=0;k<mi;k++) ans.push_back(i+1);
            for(int j=0;j<W;j++) S[i][j]-=mi;
        }
        
        bool ok=true;
        
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(S[i][j]) ok=false;
        
        if(ok){
            cout<<si(ans)<<endl;
            for(int a:ans){
                if(a>=0) cout<<"row "<<a<<"\n";
                else cout<<"col "<<-a<<"\n";
            }
        }else cout<<-1<<endl;
    }
}