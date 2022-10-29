#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;
const int mxN = 2e5+5;

ll dp[mxN][2][2][2][2][2][2];
string s;
int n;

ll f(int x, bool axor, bool bxor, bool cxor, bool la, bool lb, bool lc){
	if(x >= n)return axor&bxor&cxor;
	if(dp[x][axor][bxor][cxor][la][lb][lc] != -1)return dp[x][axor][bxor][cxor][la][lb][lc];
	ll ret = 0;
	if(s[x] == '1'){
		ret += f(x+1, axor, bxor, cxor, 1 , 1 , 1 );
		ret += f(x+1, 1   , bxor, cxor, la, 1 , 1 );
		ret += f(x+1, axor, 1   , cxor, 1 , lb, 1 );
		ret += f(x+1, axor, bxor, 1   , 1 , 1 , lc);
		ret += f(x+1, 1   , bxor, cxor, 1 , lb, lc);
		ret += f(x+1, axor, 1   , cxor, la, 1 , lc);
		ret += f(x+1, axor, bxor, 1   , la, lb, 1 );
		ret += f(x+1, axor, bxor, cxor, la, lb, lc);
	} else {
				   ret += f(x+1, axor, bxor, cxor, la, lb, lc);
		if(la)		   ret += f(x+1, 1   , bxor, cxor, la, lb, lc);
		if(lb)		   ret += f(x+1, axor, 1   , cxor, la, lb, lc);
		if(lc)		   ret += f(x+1, axor, bxor, 1   , la, lb, lc);
		if(lb && lc)	   ret += f(x+1, 1   , bxor, cxor, la, lb, lc);
		if(la && lc)	   ret += f(x+1, axor, 1   , cxor, la, lb, lc);
		if(la && lb)	   ret += f(x+1, axor, bxor, 1   , la, lb, lc);
		if(la && lb && lc) ret += f(x+1, axor, bxor, cxor, la, lb, lc);
	}
	return dp[x][axor][bxor][cxor][la][lb][lc] = ret % M;

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();

	for(int i = 0; i < mxN; ++i)for(int j = 0; j < 64; ++j)dp[i][j&1][(j&2)>>1][(j&4)>>2][(j&8)>>3][(j&16)>>4][(j&32)>>5] = -1;

	cout << f(0,0,0,0,0,0,0) << '\n';
}