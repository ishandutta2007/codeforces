#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
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
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,sz,mx[3],cnt,mxx,st,sm[3],siapa,who;
string s[3], ans[] = {"Kuro","Shiro","Katie"};
ll x[3][150];

int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,0,2)cin>>s[i];
    sz=s[0].size();
    if(n>=sz)return cout<<"Draw", 0;
    sz--;
    rep(i,0,2)rep(j,0,sz)x[i][s[i][j]]++;
    rep(i,0,2)rep(j,0,150)mx[i] = max(mx[i],x[i][j]);
    //cout<<mx[2]<<endl;
    if(mx[0]==mx[1] && mx[1]==mx[2])return cout<<"Draw", 0;
    rep(i,0,2)mxx = max(mxx,mx[i]);
    sz++;
    //cout<<"LALALA"<<endl;
    if(mxx==sz && n==1){
    	rep(i,0,2){
    		sm[i]=0;
    		if(mx[i]==mxx)mx[i]--;
    		else mx[i]++;
		}
    	mxx=0;
    	rep(i,0,2)mxx = max(mxx,mx[i]);
    	rep(i,0,2)if(mx[i]==mxx)cnt++, sm[i]=1;
    	rep(i,0,2)if(sm[i])who=i;
    	if(cnt>1)return cout<<"Draw",0;
    	else return cout<<ans[who],0;
	}
	rep(i,0,2)mx[i] = min(mx[i]+n, sz);
	rep(i,0,2)mxx = max(mxx,mx[i]);
	rep(i,0,2)if(mx[i]==mxx)cnt++, sm[i]=1;
    rep(i,0,2)if(sm[i])who=i;
    //cout<<mx[2]<<endl;
	if(cnt>1)return cout<<"Draw",0;
	else return cout<<ans[who],0;
    return 0;
}