#include <cstdio>
#include <set>
#include <string>

using namespace std;

const int MAXL = 1E3 + 10;

int n, m, q;
char s[MAXL];
set<string> a;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		a.insert(string(s));
	}
	for (int i = 0; i < m; ++i){
		scanf("%s", s);
		string t = s;
		q += a.count(t);
	}
	n -= q, m -= q;
	n += q + 1 >> 1, m += q >> 1;
	puts(n > m ? "YES" : "NO");
	return 0;
}