#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, tot, id[N], pos[N];
pair<int, int> a[N];
vector<int> bin[N];

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i].first = get(), a[i].second = i, id[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			tot += a[j] > a[i];
	printf("%d\n", tot);
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j < i; j++)
			if(a[j] > a[i]) bin[i].push_back(j);
		sort(bin[i].begin(), bin[i].end(), [](int x, int y) { return a[x] < a[y]; });
		for(auto v : bin[i]) printf("%d %d\n", v, i);
	}
	return 0;
}