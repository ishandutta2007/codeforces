#include <iostream>
#include <vector>
using namespace std;

long long n, cnt[5], t[200][5];
int send[5];

long long x(int j, long long N, int u) {
	int p = 1;
	for(int k = 1; k <= 5; k++) {
		if(n+N < 2*p*(cnt[j]+u*N) && p*(cnt[j]+u*N) <= n+N)
			return k * 500;
		p *= 2;
	}
	return 3000;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> t[i][j];
			if(t[i][j] != -1) cnt[j]++;
			if(i == 1) {
				if(t[1][j] < t[0][j] && t[1][j] != -1) {
					send[j] = 1;
				}
			}
		}
	}	
	const long long maxN = 1e9 + 7;
	long long R = maxN + 1;
	long long L = 0;
	for(int N = 0; N < 200*64; N++) {
		long long score_v = 0, score_p = 0;
		for(int j = 0; j < 5; j++) {
			if(t[0][j] != -1)
				score_v	+= x(j, N, send[j]) * (250-t[0][j]) / 250;
			if(t[1][j] != -1)
				score_p += x(j, N, send[j]) * (250-t[1][j]) / 250;
		}
		if(score_v > score_p) {
			cout << N << '\n';
			return 0;
		}
		
	}
	cout << "-1";
	return 0;
	//if(R <= maxN) cout << R <<'\n';
	//else cout << "-1\n";
}