//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define XX first
#define YY second
const int Maxn = 120;
pair<ld,pair<ld,ld> > dp[Maxn][Maxn][Maxn];
pair<ld,pair<ld,ld> > rec(int r,int s,int p){
	if(r < 0 || s < 0 || p < 0) return make_pair(0,make_pair(0,0));
	if(dp[r][s][p].first != -1) return dp[r][s][p];
	pair<ld,pair<ld,ld> > ans = make_pair(0,make_pair(0,0));
	ld sum = (ld)r * p + (ld)s * p + (ld)r * s;
	pair<ld,pair<ld,ld> > rdies = rec(r-1,s,p);
	ans.first += rdies.first * ((ld)r) * ((ld)p / sum);
	ans.YY.XX += rdies.YY.XX * ((ld)r) * ((ld)p / sum);
	ans.YY.YY += rdies.YY.YY * ((ld)r) * ((ld)p / sum);
	pair<ld,pair<ld,ld> > sdies = rec(r,s-1,p);
	ans.first += sdies.first * ((ld)s) * ((ld)r / sum);
	ans.YY.XX += sdies.YY.XX * ((ld)s) * ((ld)r / sum);
	ans.YY.YY += sdies.YY.YY * ((ld)s) * ((ld)r / sum);
	pair<ld,pair<ld,ld> > pdies = rec(r,s,p-1);
	ans.first += pdies.first * ((ld)p) * ((ld)s / sum);
	ans.YY.XX += pdies.YY.XX * ((ld)p) * ((ld)s / sum);
	ans.YY.YY += pdies.YY.YY * ((ld)p) * ((ld)s / sum);
	if(ans.YY.YY != ans.YY.YY) ans.YY.YY = 0;
	if(ans.YY.XX != ans.YY.XX) ans.YY.XX = 0;
	if(ans.XX != ans.XX) ans.XX = 0;
	return dp[r][s][p] = ans;
}
int main(){
	int s,p,r;
	cin >> r >> s >> p;
	for(int i = 0; i < Maxn;i++)
		for(int j = 0; j < Maxn;j++)
			for(int k = 0; k < Maxn;k++)
				dp[i][j][k] = make_pair(-1,make_pair(-1,-1));
	for(int i = 1; i < Maxn;i++){
		dp[i][0][0] = make_pair(1,make_pair(0,0));
		dp[0][i][0] = make_pair(0,make_pair(1,0));
		dp[0][0][i] = make_pair(0,make_pair(0,1));
	}
	pair<ld,pair<ld,ld> > ans = rec(r,s,p);
	cout << setprecision(12) << fixed << ans.first << ' ' << ans.second.first << ' ' << ans.second.second;
	return 0;
}