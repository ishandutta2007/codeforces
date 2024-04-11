#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
#define x first
#define y second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define pdi pair<double,int>
const ll MAX=110;
const int MOD=1000000000 + 7;
const ll INF=1000000000000000000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,d,jarak[MAX][MAX],tim[MAX];
pll coor[MAX];

int main(){
    cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    rep(i,2,n-1)cin>>tim[i];
    rep(i,1,n)cin>>coor[i].x>>coor[i].y;
    rep(i,1,n)rep(j,1,n){
        jarak[i][j] = (abs(coor[i].x-coor[j].x) + abs(coor[i].y-coor[j].y))*d - tim[j];
    }
    rep(i,1,n)jarak[i][i]=0;
    rep(k,1,n)rep(i,1,n)rep(j,1,n)jarak[i][j] = min(jarak[i][j], jarak[i][k] + jarak[k][j]);
    cout<<max(jarak[1][n],(ll)0)<<endl;
    return 0;
}