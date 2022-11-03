/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 552e
 */
#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int MAXN = 5E3 + 10;

ll expAdd(char *(&p));
ll expMul(char *(&p));
ll term(char *(&p));

ll expAdd(char *(&p)){
	ll ret = expMul(p);

	while (*p == '+')
		ret += expMul(++p);

	return ret;
}

ll expMul(char *(&p)){
	ll ret = term(p);

	while (*p == '*')
		ret *= term(++p);

	return ret;
}

ll term(char *(&p)){
	if (*p == '('){
		ll ret = expAdd(++p);
		++p;
		return ret;
	}
	else
		return *(p++) - '0';
}

int main(){
	char *p, s[MAXN], t[MAXN];
	scanf("%s", s);

	int len = strlen(s);
	int lenm = 1, mul[20] = {-1};
	ll ans = expAdd(p = s);
	for (int i=0;i<=len;++i)
		if (s[i] == '*' || i == len){
			for (int j=0;j<lenm;++j){
				strncpy(t, s, mul[j] + 1);
				t[mul[j] + 1] = '(';
				strncpy(t + mul[j] + 2, s + mul[j] + 1, i - mul[j] - 1);
				t[i + 1] = ')';
				strncpy(t + i + 2, s + i, len - i + 1);
				t[len + 2] = '\0';

				ans = max(ans, expAdd(p = t));
			}
			mul[lenm++] = i;
		}

	printf("%I64d\n", ans);

	return 0;
}