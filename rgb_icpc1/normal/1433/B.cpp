#include <bits/stdc++.h>
using namespace std;

int A[100];

int main() {
//	freopen("in.txt", "r", stdin);
	
	int Tc; cin >> Tc;
	while(Tc --) {
		int N; cin >> N;
		for(int i = 0; i < N; i ++) cin >> A[i];
		int st = 0, en = N - 1, cnt = 0;
		while(A[st] == 0 && st < N) st ++;
		while(A[en] == 0 && en >= 0) en --;
		for(int i = 0; i < N; i ++) if(A[i]) cnt ++;
		if(cnt == 0) cout << 0 << endl;
		else cout << en - st + 1 - cnt << endl;
	}
	
	return 0;
}