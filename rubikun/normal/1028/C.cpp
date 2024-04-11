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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> x1(N),y1(N),x2(N),y2(N),lx1(N+1),ly1(N+1),lx2(N+1),ly2(N+1),rx1(N+1),ry1(N+1),rx2(N+1),ry2(N+1);
    
    for(int i=0;i<N;i++) cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    
    lx1[0]=rx1[N]=-INF;
    ly1[0]=ry1[N]=-INF;
    lx2[0]=rx2[N]=INF;
    ly2[0]=ry2[N]=INF;
    
    for(int i=0;i<N;i++){
        lx1[i+1]=max(lx1[i],x1[i]);
        ly1[i+1]=max(ly1[i],y1[i]);
        lx2[i+1]=min(lx2[i],x2[i]);
        ly2[i+1]=min(ly2[i],y2[i]);
    }
    
    for(int i=N-1;i>=0;i--){
        rx1[i]=max(rx1[i+1],x1[i]);
        ry1[i]=max(ry1[i+1],y1[i]);
        rx2[i]=min(rx2[i+1],x2[i]);
        ry2[i]=min(ry2[i+1],y2[i]);
    }
    
    pair<int,int> ans=mp(-1,-1);
    
    for(int i=0;i<N;i++){
        pair<int,int> x=mp(-INF,INF);
        chmax(x.fi,lx1[i]);
        chmin(x.se,lx2[i]);
        chmax(x.fi,rx1[i+1]);
        chmin(x.se,rx2[i+1]);
        
        pair<int,int> y=mp(-INF,INF);
        chmax(y.fi,ly1[i]);
        chmin(y.se,ly2[i]);
        chmax(y.fi,ry1[i+1]);
        chmin(y.se,ry2[i+1]);
        
        if(x.fi<=x.se&&y.fi<=y.se) ans=mp(x.fi,y.fi);
    }
    
    cout<<ans.fi<<" "<<ans.se<<endl;
}