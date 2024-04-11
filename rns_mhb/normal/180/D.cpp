#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)

#define N 5005

char s[N], t[N], st[N];
int n, g[26], h[26], x[26];
string ans;

int main() {
    scanf("%s %s", s, t);
    int ls = strlen(s), lt = strlen(t);
    ans += 'z' + 1;
    f0(i, 0, ls) g[s[i] - 'a'] ++;
    f0(i, 0, lt) {
        bool flag = 0;
        f0(j, 0, 26) {
			if (g[j] < h[j]) {flag = 1; break;}
            x[j] = g[j] - h[j];
        }
        if (flag) break;
        f0(j, t[i]-'a'+1, 26) {
            if (x[j]) {
                st[i] = j+'a'; x[j] --;
                int now = i;
                f0(c, 0, 26) while (x[c] --) st[++ now] = c + 'a';
                ans = st;
                break;
            }
        }
        st[i] = t[i];
        h[t[i]-'a'] ++;
    }
    if (ls > lt) {
        bool flag = 0;
        f0(j, 0, 26) {
            if (g[j] < h[j]) {flag = 1; break;}
            x[j] = g[j] - h[j];
        }
        if (!flag) {
			int now = lt - 1;
			f0(j, 0, 26) while(x[j] --) st[++ now] = j + 'a';
			ans = st;
        }
    }
    if (ans[0] == 'z' + 1) puts("-1");
    else cout << ans << endl;
	return 0;
}