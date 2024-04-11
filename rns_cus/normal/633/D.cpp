#include <bits/stdc++.h>
using namespace std;
#define M 1010

int n;
int a[M];
int b[M];
int num[M];
map<int, int> mp;

int main() {
    scanf("%d", &n);
    int m = n;
    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        mp[x]++;
    }
    n = 0;
    for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
        a[++n] = it->first;
        num[n] = it->second;
    }

    int answer = 2;
    for (int i = 1; i <= n; i++) {
    	num[i]--;
    	b[0] = i;
		for (int j = 1; j <= n; j++) if (num[j]) {
			num[j]--;
			b[1] = j;

			int c;
			for (c = 2; c < m; c++) {
				int x = a[b[c-1]] + a[b[c-2]];
                b[c] = lower_bound(a + 1, a + n + 1, x) - a;
                if (b[c] > n || x != a[b[c]] || !num[b[c]]) {
                	break;
                }
                num[b[c]]--;
			}


			answer = max(answer, c);
			if (c == m) {
				printf("%d\n", m);
				return 0;
			}

			while (--c >= 1) {
				num[b[c]]++;
			}
		}
		num[i]++;
    }
    printf("%d\n", answer);
    return 0;
}