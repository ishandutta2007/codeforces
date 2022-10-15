#include <cstdio>

using namespace std;

int cnt[26];
char name[50];

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {scanf("%s", name); cnt[name[0] - 'a']++;}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] & 1)
			ans += (cnt[i] / 2) * (cnt[i] / 2) + (cnt[i] / 2 + 1) * (cnt[i] / 2 + 1);
		else
			ans += 2 * (cnt[i] / 2) * (cnt[i] / 2);
	}
	printf("%d", (ans - n) / 2);
	return 0;
}