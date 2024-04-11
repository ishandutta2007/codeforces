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
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,m,le,ri,x,cnt[2];
int main(){
    cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
        cin>>x;
        if(x==-1)cnt[1]++;
        else cnt[0]++;
    }
    rep(i,1,m){
        cin>>le>>ri;
        if((ri-le+1)%2==0 && cnt[1]>=(ri-le+1)/2 && cnt[0]>=(ri-le+1)/2)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}