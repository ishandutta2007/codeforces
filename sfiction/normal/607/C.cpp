#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E6 + 10;

int n;
char a[MAXN], b[MAXN];
int fail[MAXN];

inline char getInv(char c){
	return c == 'N' ? 'S' : c == 'E' ? 'W' : c == 'S' ? 'N' : 'E';
}

bool solve(){
	int i, j;
	fail[0] = -1;
	for (i = 1; i < n; ++i){
		for (j = fail[i - 1]; 0 <= j && a[j + 1] != a[i]; j = fail[j]);
		fail[i] = a[j + 1] == a[i] ? j + 1 : -1;
	}
	for (i = 0, j = 0; i < n; ++i)
		if (b[i] == a[j])
			j += j < n - 1;
		else if (0 < j)
			--i, j = fail[j - 1] + 1;
	return j || a[0] == b[n - 1];
}

int main(){
	scanf("%d", &n);
	--n;
	scanf("%s%s", a, b);
	for (int i = 0; i < n; ++i)
		a[i] = getInv(a[i]);
	reverse(a, a + n);
	puts(solve() ? "NO" : "YES");
	return 0;
}