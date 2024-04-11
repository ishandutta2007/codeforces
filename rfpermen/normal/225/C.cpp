#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int R,C,x,y,dp[1005][2][1005],sum[1005];
char grid[1005][1005];
int barcode(int idx,bool stat,int conse){
	//cout<<idx<<" "<<stat<<" "<<conse<<endl;
	if(conse>y)return 1e9;
	if(idx==C && conse<x)return 1e9;
	if(idx==C && conse>=x)return 0;
	if(dp[idx][stat][conse]!=-1) return dp[idx][stat][conse];
	if(stat && conse>=x){
		//cout<<min(barcode(idx+1,0,1)+R-sum[idx],barcode(idx+1,1,conse+1)+sum[idx])<<endl;
		return dp[idx][stat][conse]= min(barcode(idx+1,0,1)+R-sum[idx+1],barcode(idx+1,1,conse+1)+sum[idx+1]);
	}
	if(conse>=x){
		//cout<<min(barcode(idx+1,0,1)+R-sum[idx],barcode(idx+1,1,conse+1)+sum[idx])<<endl;
		return dp[idx][stat][conse]= min(barcode(idx+1,0,conse+1)+R-sum[idx+1],barcode(idx+1,1,1)+sum[idx+1]);
	}
	if(stat){
		//cout<<barcode(idx+1,1,conse+1)+sum[idx]<<endl;
		return dp[idx][stat][conse]=barcode(idx+1,1,conse+1)+sum[idx+1];
	}
	//cout<<barcode(idx+1,0,conse+1)+R-sum[idx]<<endl;
	return dp[idx][stat][conse]= barcode(idx+1,0,conse+1)+R-sum[idx+1];
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>R>>C>>x>>y;
	rep(r,R){
		rep(c,C)cin>>grid[r][c];
	}
	rep(c,C){
		rep(r,R)if(grid[r][c]=='.')sum[c]++;
		//cout<<sum[c]<<endl;
	}
	cout<<min(barcode(1,1,1)+sum[1],barcode(1,0,1)+R-sum[1])<<endl;
	return 0;
}