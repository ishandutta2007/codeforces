#include <cstdio>

const int N = 105;

int chill, cfrog, cmos;
int lans[N];
int cans, ans = 0x3f3f3f3f;
int d[N], mos[N];

int main()
{
	scanf("%d%d%d", &chill, &cfrog, &cmos);
	for (int i = 1; i <= cfrog; ++i) scanf("%d", &d[i]);
	for (int i = 1; i <= cmos; ++i) scanf("%d", &mos[i]);
	for (int i = 1; i <= cfrog; ++i) {
		int cur = 0;
		for (int j = 1; j <= cmos; ++j) if (mos[j] % d[i] == 0) ++cur;
		if (cur == ans) 
			lans[++cans] = i;
		else if (cur < ans) {
			ans = cur;
			lans[cans = 1] = i;
		}
	}
	printf("%d\n", cans);
	for (int i = 1; i <= cans; ++i) printf("%d%c", lans[i], i == cans ? '\n' : ' ');
}