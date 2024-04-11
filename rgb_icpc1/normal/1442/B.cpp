#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define MX 200005
int A[MX], B[MX], pos[MX];
bool chk[MX];

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Tc; cin >> Tc;
	while(Tc --) {
		memset(chk, 0, sizeof(chk));
		
		int N, M; cin >> N >> M;
		for(int i = 0; i < N; i ++) {
			cin >> A[i];
			pos[A[i]] = i;
		}
		for(int i = 0; i < M; i ++) {
			cin >> B[i];
			chk[B[i]] = 1;
		}
		int ans = 1;
		for(int i = 0; i < M; i ++) {
			int t = 0, p = pos[B[i]];
			if(p - 1 >= 0 && !chk[A[p - 1]]) t ++;
			if(p + 1 < N && !chk[A[p + 1]]) t ++;
			ans = 1LL * ans * t % MOD;
			chk[B[i]] = 0;
		}
		cout << ans << endl;
	}
	
	return 0;
}