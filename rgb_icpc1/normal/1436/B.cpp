#include <bits/stdc++.h>
using namespace std;

#define MX 10000005
int A[MX], B[MX];
bool flg[MX];

void sieve() {
	for(int i = 2; i < MX; i ++) if(!flg[i]) {
		for(int j = i * 2; j < MX; j += i) flg[j] = 1;
	}
}

void calc(int n) {
	for(int i = 1; i < 100000; i ++) if(flg[i]) {
		int a = i * n + 1, b = i * n - 1;
		if(!flg[a] && flg[i + 1]) { A[n] = i; break; }
		if(!flg[b] && flg[i - 1]) { B[n] = i; break; }
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	sieve();
	for(int i = 2; i <= 100; i ++) calc(i);

	int Tc; cin >> Tc;
	while(Tc --) {
		int N; cin >> N;
		if(A[N]) {
			for(int i = 0; i < N; i ++) {
				for(int j = 0; j < N; j ++) {
					if(j) cout << ' ';
					if(i == j) cout << A[N] + 1;
					else cout << A[N];
				}
				cout << endl;
			}
		}	
		else {
			for(int i = 0; i < N; i ++) {
				for(int j = 0; j < N; j ++) {
					if(j) cout << ' ';
					if(i == j) cout << B[N] - 1;
					else cout << B[N];
				}
				cout << endl;
			}
		}	
	}
	
	return 0;
}