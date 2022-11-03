/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 519D
 */
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int SIGMA = 26, MAXN = 1E5 + 100;

int w[SIGMA];
char s[MAXN];
map<long long, int> lst[SIGMA];

int main(){
	for (int i=0;i<SIGMA;++i)
		scanf("%d", &w[i]);
	
	scanf("%s", s);
	int n = strlen(s);
	long long sum = 0, ans = 0;
	for (int i=0;i<n;++i){
		int c = s[i] - 'a';
		if (lst[c].find(sum) != lst[c].end())
			ans += lst[c][sum];
		sum += w[c];
		++lst[c][sum];
	}
	printf("%I64d\n", ans);
	return 0;
}