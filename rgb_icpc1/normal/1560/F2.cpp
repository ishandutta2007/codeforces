#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;

int Tc, K;
char N[50];
int f[10];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (cin >> Tc; Tc--; ) {
		cin >> N >> K;
		int LN = strlen(N);
		while(1){
			memset(f, 0, sizeof f);
			int cnt = 0, i;
			for(i = 0 ; i < LN ; i ++) {
				if(!f[N[i] - '0']) f[N[i] - '0'] = 1, cnt ++;
				if(cnt > K) break;
			}
			if(i == LN) break;
			while(1) {
				N[i] = '0' + (N[i] - '0' + 1) % 10;
				if(N[i] != '0') break;
				i --;
			}
			for(int m = i ; m < LN ; m ++) {
				if(m == i) continue;
				N[m] = '0';
			}
		}
		cout << N << endl;
	}

	return 0;

}