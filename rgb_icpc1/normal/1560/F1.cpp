#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;

int Tc, K;
char rlt[50], N[50], tmp[50], tmpp[50];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N >> K;
		int LN = strlen(N);
		for(int i = 1 ; i < 10 ; i ++) {
			memset(rlt, 0, sizeof rlt);
			for(int j = 0 ; j < LN ; j ++) rlt[j] = ('0' + i);
			if(atol(rlt) >= atol(N)) break;
		}
		if(K == 2) {
			for(int i = 0 ; i < 10 ; i ++) {
				for(int j = i + 1 ; j < 10 ; j ++) {
					int k;
					for(k = 0 ; k < LN ; k ++) {
						if(N[k] != '0' + i && N[k] != '0' + j) break;
						if(k + 1 < LN) {
							if(N[k + 1] - '0' < i) {
								strcpy(tmp, N);
								for(int m = k + 1 ; m < LN ; m ++) tmp[m] = '0' + i;
								if(atol(tmp) < atol(rlt)) strcpy(rlt, tmp);
							}else if(N[k + 1] - '0' < j) {
								strcpy(tmp, N);
								for(int m = k + 1 ; m < LN ; m ++) tmp[m] = ((m == k + 1) ? '0' + j : '0' + i);
								if(atol(tmp) < atol(rlt)) strcpy(rlt, tmp);
							}
						}
					}
					if(k == LN) strcpy(rlt, N);
				}
			}
		}
		cout << rlt << endl;
	}

	return 0;

}