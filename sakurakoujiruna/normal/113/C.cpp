#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e8 + 11;
bitset <N> np;
bitset <N / 4> c;
int p[16252326], pc = 0;

int main() {
	np[1] = true;
	for(int i = 2; i < N; i ++) {
		if(!np[i]) p[pc ++] = i;
		for(int j = 0; j < pc && i * p[j] < N; j ++) {
			np[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	ios :: sync_with_stdio(false);
	/*
	for(int i = 1; i * i < N; i += 2)
		for(int j = 2; i * i + j * j < N; j += 2)
			c[(i * i + j * j) / 4] = 1;
		*/	
	int l, r; cin >> l >> r;
	//int l = 0, r = 0;
	int ans = 0;
	for(int i = 1; i < N; i += 4) if(!np[i])
		if(l <= i && i <= r /*&& c[i / 4]*/) ans ++;
	if(l <= 2 && 2 <= r) ans ++;
	cout << ans << '\n';
}