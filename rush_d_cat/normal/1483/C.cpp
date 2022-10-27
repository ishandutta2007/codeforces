#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
LL mx[N<<2];
void update(int l,int r,int rt,int pos,LL x){
	if(l==r) {
		mx[rt]=x; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	mx[rt]=max(mx[rt<<1], mx[rt<<1|1]);
}
LL query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) return mx[rt];
	int mid=(l+r)>>1;
	LL ans=-1e18;
	if(L<=mid) ans=max(ans,query(l,mid,rt<<1,L,R));
	if(R >mid) ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	vector<int> h(n), b(n);
	for (int i = 0; i < n; i ++) cin >> h[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	vector<int> prev(n);
	vector<int> stk(n); int top = 0;
	for (int i = 0; i < n; i ++) {
		while (top > 0 && h[i] < h[stk[top-1]]) --top;
		prev[i] = (top==0?-1:stk[top-1]);
		stk[top++] = i;
	}
	vector<LL> dp(n);
	for (int i = 0; i < n; i ++) {
		int pr = prev[i];
		dp[i] = -1e18;
		//printf("i=%d,prev=%d\n", i,prev[i]);
		if (pr >= 0) {
			dp[i] = max(dp[i], dp[pr]);
			dp[i] = max(dp[i], query(0,n-1,1,pr,i-1) + b[i]);
		}
		if (pr == -1) {
			dp[i] = max(dp[i], (LL)b[i]);
			if (i>=1) dp[i] = max(dp[i], query(0,n-1,1,0,i-1) + b[i]);
		}

		update(0,n-1,1,i,dp[i]);
		//printf("dp[%d]=%lld\n", i, dp[i]);
	}
	cout << dp[n-1] << endl;
}