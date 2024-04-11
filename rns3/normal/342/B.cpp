#include <bits/stdc++.h>
using namespace std;

char tag;
int n, m, s, f;

#define N 100010

int t[N], le[N], ri[N];

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &f);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &t[i], &le[i], &ri[i]);
	}
	if (s > f) {
		tag = 'L';
		int now = s, ii = 1, time = 1;
		while (now > f) {
            while (time > t[ii]) ii ++;
            if (time == t[ii] && ((now - 1 <= ri[ii] && now - 1 >= le[ii])|| (now >= le[ii] && now <= ri[ii]))) printf("X");
            else {
				now --;
				printf("%c", tag);
            }
            time ++;
		}
	}
	else {
		tag = 'R';
		int now = s, ii = 1, time = 1;
        while (now < f) {
			while (time > t[ii]) ii ++;
			if (time == t[ii] && ((now + 1 >= le[ii] && now + 1 <= ri[ii]) || (now <= ri[ii] && now >= le[ii]))) printf("X");
			else {
				now ++;
				printf("%c", tag);
			}
			time ++;
        }
	}
	return 0;
}