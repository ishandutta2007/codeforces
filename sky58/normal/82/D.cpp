#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
//vector <pint> t;
int dp[1100][1100];int zi[1100];
vector <string> out;int n;
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int rec(int a,int b){
	if(a==n-1){
		//out.pb(moji(a+1)+' '+moji(b+1));
		return dp[a][b]=max(zi[a],zi[b]);
	}
	if(a==n){
		//out.pb(moji(b+1));
		return dp[a][b]=zi[b];
	}
	if(dp[a][b]>-1) return dp[a][b];
	vector <pint> c;
	c.pb(mp(zi[a],a));c.pb(mp(zi[a+1],a+1));c.pb(mp(zi[b],b));
	sort(c.begin(),c.end());
	int x=c[1].fi+rec(a+2,c[2].se),y=c[2].fi+rec(a+2,c[0].se);
/*	if(x<y){
		out.pb(moji(c[0].se+1)+' '+moji(c[1].se+1));dp[a][b]=x;
	}
	else{
		out.pb(moji(c[2].se+1)+' '+moji(c[1].se+1));dp[a][b]=y;
	}
*/
	return dp[a][b]=min(x,y);
}
void dfs(int a,int b){
	if(a==n-1){
		out.pb(moji(b+1)+' '+moji(a+1));return;
		//return max(zi[a],zi[b]);
	}
	if(a==n){
		out.pb(moji(b+1));return;
		//return zi[b];
	}
//	cout<<dp[a][b]<<' '<<dp[a+2][b]<<' '<<dp[a+2][a+1]<<' '<<dp[a+2][a]<<endl;
	if(dp[a][b]-max(zi[a],zi[a+1])==dp[a+2][b]){
		out.pb(moji(a+1)+' '+moji(a+2));dfs(a+2,b);
	}
	else if(dp[a][b]-max(zi[a],zi[b])==dp[a+2][a+1]){
		out.pb(moji(b+1)+' '+moji(a+1));dfs(a+2,a+1);
	}
	else{
		out.pb(moji(b+1)+' '+moji(a+2));dfs(a+2,a);
	}
	return;
}
int main()
{
	int i,j;cin>>n;
	for(i=0;i<n;i++){
		scanf("%d",&zi[i]);//t.pb(mp(a,i+1));
	}
	for(i=0;i<1100;i++) for(j=0;j<1100;j++) dp[i][j]=-1;
	cout<<rec(1,0)<<endl;dfs(1,0);
//	reverse(out.begin(),out.end());
	for(i=0;i<out.size();i++) cout<<out[i]<<endl;
	return 0;
}