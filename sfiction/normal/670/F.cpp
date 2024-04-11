#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 1E6 + 10;

int n, m;
char s[MAXN], s1[MAXN];
int cnt[10];

int main(){
	scanf("%s%s", s, s1);
	int n = strlen(s), m = strlen(s1);
	if (n == 2){
		puts(s1);
		return 0;
	}
	for (int i = 0; i < n; ++i)
		++cnt[s[i] - '0'];
	int n0 = 1, n1 = -1;
	for (int e = 10; ; ++n0, e *= 10)
		if (n <= e - 1 + n0){
			n1 = n - n0;
			break;
		}
	for (int t = n1; t; t /= 10)
		--cnt[t % 10];

	for (int i = 0; i < m; ++i)
		--cnt[s1[i] - '0'];
	
	string a[3];

	if (s1[0] > '0'){
		a[0] = s1;
		for (int i = 0; i < 10; ++i)
			a[0] += string(cnt[i], '0' + i);
	}

	int r = s1[0] - '0', f = 1;
	for (; f < 10 && cnt[f] == 0; ++f);

	if (f < 10){
		a[1] = string(1, '0' + f);
		--cnt[f];
		for (int i = 0; i < r; ++i)
			a[1] += string(cnt[i], '0' + i);
		a[2] = a[1];
		a[1] += s1;
		a[1] += string(cnt[r], '0' + r);
		a[2] += string(cnt[r], '0' + r);
		a[2] += s1;
		for (int i = r + 1; i < 10; ++i){
			a[1] += string(cnt[i], '0' + i);
			a[2] += string(cnt[i], '0' + i);
		}
	}

	sort(a, a + 3);
	int ans = 0;
	for (; a[ans].size() == 0; ++ans);
	puts(a[ans].c_str());

	return 0;
}