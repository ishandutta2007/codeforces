#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 21E2 + 10;

char a[MAXN], b[MAXN];
char s[MAXN];

PII KMP(const char *p, const char *s){
	static int fail[MAXN] = {-1};
	int i, j;
	for (i = 1, j = 0; p[i]; ++i){
		for (j = fail[i - 1]; ~j && p[i] != p[j + 1]; j = fail[j]);
		fail[i] = p[i] == p[j + 1] ? j + 1 : -1;
	}
	int ret, retlen = 0;
	for (i = j = 0; s[i] && p[j]; ++i)
		if (s[i] == p[j]){
			++j;
			if (retlen < j){
				retlen = j;
				ret = i;
			}
		}
		else if (j){
			j = fail[j - 1] + 1;
			--i;
		}
	return PII(ret - retlen + 1, retlen);
}

int main(){
	scanf("%s%s", a, s);
	int n = strlen(a);
	strcpy(b, a);
	reverse(b, b + n);

	vector<PII> lst;
	for (int i = 0; s[i];){
		PII ra = KMP(s + i, a), rb = KMP(s + i, b);
		if (ra.nd == 0 && rb.nd == 0){
			lst.clear();
			break;
		}
		else if (ra.nd >= rb.nd){
			lst.push_back(PII(ra.st + 1, ra.st + ra.nd));
			i += ra.nd;
		}
		else{
			lst.push_back(PII(n - rb.st, n + 1 - rb.st - rb.nd));
			i += rb.nd;
		}
	}
	if (lst.size()){
		printf("%d\n", (int)lst.size());
		for (int i = 0; i < lst.size(); ++i)
			printf("%d %d\n", lst[i].st, lst[i].nd);
	}
	else
		puts("-1");
	return 0;
}