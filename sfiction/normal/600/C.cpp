#include <cctype>
#include <cstdio>
#include <string>

using namespace std;

int cnt[26];

int main(){
	char c;
	while (islower(c = getchar()))
		++cnt[c - 'a'];
	for (int l = 0, r = 25; l < r; ++l, --r){
		for (; l < r && cnt[l] % 2 == 0; ++l);
		for (; l < r && cnt[r] % 2 == 0; --r);
		if (l < r)
			++cnt[l], --cnt[r];
	}
	int p = -1;
	for (int i = 0; i < 26; ++i)
		if (cnt[i] & 1)
			p = i;
	for (int i = 0; i < 26; ++i)
		printf("%s", string(cnt[i] >> 1, 'a' + i).c_str());
	if (~p)
		putchar('a' + p);
	for (int i = 25; i >= 0; --i)
		printf("%s", string(cnt[i] >> 1, 'a' + i).c_str());

	return 0;
}