#include <bits/stdc++.h>
using namespace std;
#define M 50500
typedef long long ll;

char s[M][55];
char a[105], b[105];
int id[M];

bool cmp(int i, int j) {
	strcpy(a, s[i]);
	strcat(a, s[j]);
	strcpy(b, s[j]);
	strcat(b, s[i]);
	return strcmp(a, b) < 0;
}

int main() {
	//freopen("C3.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		id[i] = i;
	}
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%s", s[id[i]]);
	}
	puts("");
	return 0;
}