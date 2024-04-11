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
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
const int MAX=100005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int v1,v2,t,d,ans;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>v1>>v2>>t>>d;
    ans=v1;
    rep(i,2,t){
        if(v1+d<=v2+d*(t-i))v1+=d;
        else if(v1<=v2+d*(t-i))v1+=v2+d*(t-i)-v1;
        else if(v1>v2+d*(t-i))v1-=min(d,v1-d*(t-i)-v2);
        if(i==t)ans+=v2;
        else ans+=v1;
        //cout<<v1<<"-------"<<i<<"   "<<d*(t-i)<<endl;
    }
    cout<<ans<<endl;
    return 0;
}