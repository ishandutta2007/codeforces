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
const int mod=998244353,MAX=1005,INF=1<<30;
double P[MAX][MAX];
double dis[MAX],rem[MAX],sum[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x;cin>>x;
            P[i][j]=x;
            P[i][j]/=100;
        }
        dis[i]=INF;
        rem[i]=1;
    }
    dis[N-1]=0;
    vector<int> goal={N-1};
    for(int t=0;t<N-1;t++){
        pair<double,int> mi=mp(INF,-1);
        for(int i=0;i<N;i++){
            if(dis[i]!=INF) continue;
            int a=goal.back();
            sum[i]+=rem[i]*P[i][a]*dis[a];
            rem[i]*=(1.0-P[i][a]);
            if(rem[i]<1) chmin(mi,mp((sum[i]+1)/(1.0-rem[i]),i));
        }
        goal.push_back(mi.se);
        dis[mi.se]=mi.fi;
        
        if(mi.se==0) break;
    }
    
    cout<<fixed<<setprecision(25)<<dis[0]<<endl;
    
}