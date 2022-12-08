#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, k, p[N], vis[N], bin[N], top, cnt[N], f[N];

int GetMx() {
	int sum = 0, cnt = 0, res = 0, tmp = k;
	for(int i = 1; i <= top; i++) sum += bin[i] / 2, cnt += bin[i] % 2;
	if(sum >= tmp) return tmp * 2;
	tmp -= sum, res += sum * 2;
	res += min(tmp, cnt);
	return res;
}

int GetMn() {
	for(int i = 1; i <= top; i++) ++cnt[bin[i]];
	memset(bin, 0, sizeof(bin)), top = 0;
	for(int i = 1; i <= n; i++) {
		int now = 1, tmp = cnt[i];
		if(!tmp) continue;
		while(now < tmp) 
			bin[++top] = now * i, tmp -= now, now <<= 1;
		bin[++top] = tmp * i;
	}
	f[0] = 1;
	for(int i = 1; i <= top; i++)
		for(int j = k; j >= bin[i]; j--)
			f[j] |= f[j - bin[i]];
	if(f[k]) return k;
	else return min(k + 1, n);
}

int main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) p[i] = get();
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int now = i, cnt = 0;
		while(!vis[now]) vis[now] = 1, now = p[now], ++cnt;
		bin[++top] = cnt;
	}
	cout << GetMn() << " " << GetMx();
	return 0;
}