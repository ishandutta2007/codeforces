//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lg = 45;
const ll Maxn = 1e5 + 9;
ll ch[Maxn * lg][2],nx;
ll pre[Maxn],suf[Maxn],arr[Maxn];
ll ith(ll x,int i){
	if((1LL << i) & x) return 1;
	return 0;
}
void ins(ll x){
	int cur = 0;
	for(int i = lg - 1; i + 1;--i){
		if(ch[cur][ith(x,i)] + 1) cur = ch[cur][ith(x,i)];
		else ch[cur][ith(x,i)] = ++nx,cur = nx;
	}
	return;
}
ll find_max(ll x){
	int cur = 0;
	ll res = 0;
	for(int i = lg - 1; i + 1;--i){
		if(ch[cur][ith(x,i) ^ 1] + 1) cur = ch[cur][ith(x,i) ^ 1],res += 1LL << i;
		else cur = ch[cur][ith(x,i)];
	}
	return res;
}
int main(){
	memset(ch,-1,sizeof ch);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i];
	for(int i = 0; i < n;i++) pre[i + 1] = pre[i] ^ arr[i];
	for(int i = n - 1; i + 1;--i) suf[i] = suf[i + 1] ^ arr[i];
	for(int i = 0; i <= n;i++) ins(pre[i]);
	ll ans = 0;
	for(int i = 0; i <= n;i++) ans = max(ans,find_max(suf[i]));
	cout << ans << endl;
	return 0;
}