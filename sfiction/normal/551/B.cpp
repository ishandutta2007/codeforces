/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 551B
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 100, SIGMA = 26;
const int INF = 0x7fffffff;

char sa[MAXN], sb[MAXN], sc[MAXN];
int a[SIGMA], b[SIGMA], c[SIGMA];

void getCnt(int (&a)[SIGMA], char s[]){
	memset(a, 0, sizeof(a));
	scanf("%s", s);
	for (char *p = s; *p; ++p)
		++a[*p - 'a'];
}

int main(){
	getCnt(a, sa);
	getCnt(b, sb);
	getCnt(c, sc);

	int ansb = 0, ansc = 0;
	for (int i = 0; true; ++i){
		bool flag = true;
		for (int j = 0; j < SIGMA; ++j)
			if (a[j] < b[j] * i)
				flag = false;
		if (!flag)
			break;

		int t = INF;
		for (int j = 0; j < SIGMA; ++j)
			t = min(t, c[j] == 0 ? INF : (a[j] - b[j] * i) / c[j]);

		if (ansb + ansc < i + t){
			ansb = i;
			ansc = t;
		}
	}

	for (int i = 0; i < ansb; ++i)
		printf("%s", sb);
	for (int i = 0; i < ansc; ++i)
		printf("%s", sc);
	for (int i = 0; i < SIGMA; ++i)
		for (int j = a[i] - b[i] * ansb - c[i] * ansc; j; --j)
			putchar('a' + i);

	return 0;
}