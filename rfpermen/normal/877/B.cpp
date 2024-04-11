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
string s;
pii x[5005];
int dp[3][5005],cnt,cs;
char nw;
int f(int st,int pos){
	if(pos>cnt)return 0;
	if(st>2)return 0;
	if(dp[st][pos]!=-1)return dp[st][pos];
	if(st%2!=x[pos].fi && st+1<3)return dp[st][pos] = max(f(st,pos+1),f(st+1,pos+1)+x[pos].se);
	else if(st%2!=x[pos].fi)return dp[st][pos] = max(f(st,pos+1),f(st+1,pos+1));
	return dp[st][pos] = max(f(st,pos+1),f(st+1,pos+1))+x[pos].se;
}
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
	cin>>s;
	nw=s[0]; cs=1;
	rep(i,1,s.size()-1){
		if(nw==s[i])cs++;
		else cnt++, x[cnt]=mp(nw-'a',cs), cs=1, nw=s[i];
	}
	cnt++, x[cnt]=mp(nw-'a',cs);
	//rep(i,1,cnt)cout<<x[i].fi<<" "<<x[i].se<<endl;
	cout<<f(0,1)<<endl;
    return 0;
}