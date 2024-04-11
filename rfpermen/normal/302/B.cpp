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
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define pdi pair<double,int>
const ll MAX=100010;
const int MOD=1000000000 + 7;
const ll INF=1000000000000000000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,m,le,ri,mid,x,y,pre[MAX],ans;
int main(){
    cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x>>y, pre[i] = pre[i-1] + x*y;
    rep(i,1,m){
        cin>>x;
        le=1, ri=n;ans=n;
        while(le<=ri){
            mid = (le+ri)/2;
            if(pre[mid]>=x)ri=mid-1, ans=mid;
            else le=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}