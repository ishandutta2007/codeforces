#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPI;

const int MAXN = 1E5 + 10;
const char *sa[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int n;
char s[20];
int a[6];
PPI b[MAXN];
int ans[MAXN];

int getType(char *p, char *q){
	int i = 0;
	for (; strncmp(p, sa[i], q - p); ++i);
	return i;
}

int main(){
	for (int i = 0; i < 6; ++i)
		scanf("%d", &a[i]);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		int m = find(s, s + strlen(s), ',') - s;
		b[i].st.st = getType(s, s + m);
		b[i].st.nd = b[i].st.st + (s[m] == ',');
		b[i].nd = i;
	}
	sort(b, b + n);
	bool flag = true;
	for (int i = 0; i < n; ++i){
		if (a[b[i].st.st] > 0)
			--a[ans[b[i].nd] = b[i].st.st];
		else if (a[b[i].st.nd] > 0)
			--a[ans[b[i].nd] = b[i].st.nd];
		else
			flag = false;
	}
	puts(flag ? "YES" : "NO");
	if (flag)
		for (int i = 0; i < n; ++i)
			puts(sa[ans[i]]);
	return 0;
}