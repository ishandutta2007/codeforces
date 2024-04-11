#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 100001;

char str[NMAX];

int main() {
	int n; scanf("%d", &n);
	vector<ll> lrun(26, 0);
	vector<bool> isInString(26, false);
	for (int pi = 0; pi < n; ++pi) {
		scanf("%s", str);
		int clen = strlen(str);
		int prefBreak = 0, suffBreak = clen - 1;
		while (prefBreak < clen && str[0] == str[prefBreak]) ++prefBreak;
		while (suffBreak >= 0 && str[clen - 1] == str[suffBreak]) --suffBreak;
//		printf("pb sb %d %d\n", prefBreak, suffBreak);
		if (prefBreak == clen) {
			for (int i = 0; i < 26; ++i) {
				if (i + 'a' == str[0]) {
//					printf("spc %d now %d\n", i, lrun[i]);
					lrun[i] += (lrun[i] + 1) * clen;
				} else {
					lrun[i] = (isInString[i] ? 1 : 0);
				}
				if (lrun[i] > 1000000000)  {
					lrun[i] = 1000000001;
				}
			}
		} else {
			// update with the info inside the string
			int crlen = 0;
			vector<int> intruns(26, 0);
			for (int i = 0; i < clen; ++i) {
				if (i == 0 || str[i] != str[i-1]) {
					crlen = 1;
				} else {
					++crlen;
				}
				intruns[str[i] - 'a'] = max(intruns[str[i] - 'a'], crlen);
			}
			vector<int> spruns(26, 0);
			for (int i = 0; i < 26; ++i) if (isInString[i]) spruns[i] = 1;
			if (isInString[str[0] - 'a']) spruns[str[0] - 'a'] += prefBreak;
			if (isInString[str[clen - 1] - 'a']) spruns[str[clen - 1] - 'a'] += (clen - suffBreak) - 1;
			for (int i = 0; i < 26; ++i) {
				if (isInString[i]) lrun[i] = 1;
//				printf("ch %d %d %d %d\n", i, lrun[i], spruns[i], intruns[i]);
				lrun[i] = max(lrun[i], (ll)max(spruns[i], intruns[i]));
			}
		}
		for (int i = 0; i < clen; ++i) isInString[str[i] - 'a'] = true;
	}
	printf("%lld\n", *max_element(begin(lrun), end(lrun)));
	return 0;
}