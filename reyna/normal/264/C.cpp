//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 9;
typedef long long ll;
ll dp[Maxn],v[Maxn],c[Maxn],last[Maxn];
ll id1,id2;
int main(){
	ios_base::sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1; i <= n;i++) cin >> v[i];
	for(int i = 1; i <= n;i++) cin >> c[i];
	while(q--){
		memset(last,-1,sizeof last);
		for(int i = 1; i <= n;i++) dp[i] = -1e18;
		ll a,b;
		cin >> a >> b;
		id1 = 0,id2 = 0;
		last[0] = 0;
		for(int i = 1; i <= n;i++){
			if(last[c[i]] != -1){
				dp[i] = max(dp[i],dp[last[c[i]]] + v[i] * a);
			}
			int id = id1;
			if(id1 == last[c[i]]){
				id = id2;
			}
			dp[i] = max(dp[i],dp[id] + v[i] * b);
			if(c[id1] == c[i] && dp[id1] < dp[i]) id1 = i;
			else if(c[id1] == c[i]);
			else if(c[id1] != c[i] && dp[id1] < dp[i]) id2 = id1,id1 = i;
			else if(c[id2] == c[i] && dp[i] > dp[id2]) id2 = i;
			else if(c[id2] != c[i] && dp[i] > dp[id2]) id2 = i;
			if(last[c[i]] == -1 || dp[i] > dp[last[c[i]]]) last[c[i]] = i;
		}
		cout << dp[id1] << '\n';
	}
	return 0;
}