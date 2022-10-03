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
const int mod=1000000007,MAX=600005,INF=1<<30;
const int D=300000;

vector<int> wh[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<int,int>> A,B;
    
    
    for(int i=0;i<N;i++){
        int x,y;cin>>x>>y;
        bool f=false;
        if((abs(x)+abs(y))%2==0){
            f=true;
            y++;
        }
        int xx=x+y,yy=x-y;
        xx+=D;
        yy+=D;
        if(f) B.push_back(mp(xx,yy));
        else A.push_back(mp(xx,yy));
    }
    
    ll ans=0;
    
    for(int q=0;q<2;q++){
        for(auto a:A){
            wh[a.se].push_back(a.fi);
        }
        
        vector<pair<int,int>> L(MAX),R(MAX);
        
        {
            int l=INF,r=-INF;
            for(int i=0;i<MAX-1;i++){
                for(int x:wh[i]){
                    chmin(l,x+1);
                    chmax(r,x-1);
                }
                L[i+1]=mp(l,r);
            }
        }
        
        {
            int l=INF,r=-INF;
            for(int i=MAX-1;i>=1;i--){
                for(int x:wh[i]){
                    chmin(l,x+1);
                    chmax(r,x-1);
                }
                R[i-1]=mp(l,r);
            }
        }
        
        for(int i=1;i<MAX-1;i++){
            int l=max(L[i].fi,R[i].fi),r=min(L[i].se,R[i].se);
            if(l>r) continue;
            if(i&1) continue;
            
            int tasu=r/2-(l-1)/2;
            ans+=tasu;
        }
        
        for(int i=0;i<MAX;i++) wh[i].clear();
        swap(A,B);
    }
    
    cout<<ans<<endl;
    
}