#include <bits/stdc++.h>

using namespace std;

int p[10];
vector<map<int, int>> s(10);

void f(int x) {
	int t;
	for (int i = 1; i <= 9; i++)
		for (int j = i; j <= 9; j++) {
			t = x % p[j] / p[j - i];
			if (s[i][t] != -1) {
				for (int k = i; k > 0; k--)
					printf("%d", t % p[k] / p[k - 1]);
				printf("\n");
				return;
			}
		}
}

int main() {
	p[0] = 1;
	for (int i = 0; i < 9; i++)
		p[i + 1] = p[i] * 10;
	int n, t;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= 9; j++)
			for (int k = 0; k < j; k++) {
				t = a[i] % p[j] / p[k];
				if (s[j - k][t] > 0 && s[j - k][t] < i + 1)
					s[j - k][t] = -1;
				else if (s[j - k][t] == 0)
					s[j - k][t] = i + 1;
			}
	}
	for (int i = 0; i < n; i++)
		f(a[i]);
}