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
const ll MAX=10010;
const int MOD=1000000000 + 7;
const ll INF=1000000000000000000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
int n,pre[MAX],cnt,ans,mn;

int main(){
    cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n*2-1)cin>>pre[i];
    rep(i,1,2*n-1)if(pre[i]<0)cnt++;

    rep(i,1,2*n-1)pre[i] = abs(pre[i]);
    sort(pre+1,pre+2*n);
    rep(i,1,2*n-1)ans+=pre[i];
    if(n&1)mn=0;
    else if(cnt%2==0 && n%2==0)mn=0;
    else mn=1;
    rep(i,1,mn)ans-=2*pre[i];
    cout<<ans<<endl;
    return 0;
}