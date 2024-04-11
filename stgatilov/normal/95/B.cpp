#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

string NextLucky(string s) {
	int l = s.size();
	int i;
	for (i = 0; i<l; i++) if (s[i] != '4' && s[i] != '7') break;
	if (i == l) return s;

	bool ok = false;
	if (s[i] <= '4') { s[i] = '4'; ok = true; }
	else if (s[i] <= '7') { s[i] = '7'; ok = true; }
	if (ok) {
		for (int j = i+1; j<l; j++) s[j] = '4';
		return s;
	}
    
	while (i>=0 && s[i] >= '7') i--;
	if (i < 0) return string(l+1, '4');

	s[i] = '7';
	for (int j = i+1; j<l; j++) s[j] = '4';
	return s;
}

string NextVery(string s) {
	int l = s.size();

	if (l % 2 == 0) {
		int best = -1;
    int bdiff = 0;
		int c4 = 0;
		int c7 = 0;

		for (int i = 0; i<l; i++) {
			if (s[i] == '4') c4++;
			if (s[i] == '7') c7++;

			if (s[i] == '4') {
        int dff = (c4-1) - (c7+1);
        if (abs(dff) <= l - (i+1)) {
					best = i;
          bdiff = dff;
        }
			}
		}
		if (c4 == c7) return s;

		if (best >= 0) {
			s[best] = '7';

			c4 = 0;  c7 = 0;
			for (int i = best+1; i<l; i++) {
				if (s[i] == '4') c4++;
				if (s[i] == '7') c7++;
			}

			int rem = l - (best+1);
			int k4 = (rem - bdiff) / 2;
			int k7 = (rem + bdiff) / 2;
			for (int i = best+1; i<l; i++) {
				if (k4) {
					s[i] = '4';
					k4--;
				}
				else s[i] = '7';
			}

			return s;
		}

		l++;
	}

	l++;
	return string(l/2, '4') + string(l/2, '7');
}

string str;

char buff[1<<20];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
//	while (scanf("%s", buff) == 1) {
	scanf("%s", buff);
		str = buff;

		str = NextLucky(str);
//		printf("%s ", str.c_str());

		str = NextVery(str);
		printf("%s\n", str.c_str());
//	}

	return 0;
}