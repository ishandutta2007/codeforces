//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int lg = 17;
int t[(1 << lg + 1) + 1];
int is_or[(1 << lg + 1) + 1];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int i = (1 << n); i < (1 << n + 1);i++) cin >> t[i];
	int c = 0;
	for(int lv = n - 1; lv + 1;--lv){
		for(int j = 1 << lv; j < (1 << lv + 1);j++){
			int l = j << 1,r = l | 1;
			is_or[j] = c ^ 1;
			if(c) t[j] = t[l] ^ t[r];
			else t[j] = t[l] | t[r];
		}
		c ^= 1;
	}
	for(int i = 0; i < m;i++){
		int p,b;
		cin >> p >> b;
		int v = (1 << n) + p - 1;
		t[v] = b;
		v >>= 1;
		while(v){
			if(is_or[v]) t[v] = t[v<<1] | t[v<<1|1];
			else t[v] = t[v<<1] ^ t[v<<1|1];
			v >>= 1;
		}
		cout << t[1] << '\n';
	}
	return 0;
}