#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e6 + 7;

ll n, m, ans, p;
char ss[N], ch;
string s;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d%d ", &n, &m);
    scanf("%s ", ss);
    s = ss;
    for (int i = 1; i < n; i++)
    	if (s[i] == '.' && s[i - 1] == '.')
    		ans++;
    s = "@" + s + "@";
    while (m --> 0) {
    	scanf("%d %c ", &p, &ch);
    	if (ch == '.' && s[p] != '.') {
    		if (s[p - 1] == '.') ans++;
    		if (s[p + 1] == '.') ans++;
    		s[p] = '.';
    	} 
    	if (ch != '.' && s[p] == '.') {
    		if (s[p - 1] == '.') ans--;
    		if (s[p + 1] == '.') ans--;
    		s[p] = 's';
    	}
    	printf("%d\n", ans);
    }
}