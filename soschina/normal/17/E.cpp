#include <cstdio>
#include <cctype>
#define MOD 51123987
using namespace std;
const int MAXN = 2e6 + 5;

inline int min(const int &a, const int &b){
	return a < b ? a : b;
}

inline void read(int &x){
	x = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	do{
		x *= 10;
		x += c - '0';
		c = getchar();
	}while(isdigit(c));
}

char s[MAXN<<1] = {'@', '#'};
int n, len[MAXN<<1], p, l, r = 1;
long long start[MAXN<<1], end[MAXN<<1], sum;

int main(){
	read(n);
	l = n = (n << 1) + 1;
	for(int i = 2; i < n; i += 2){
		s[i] = getchar();
		s[i + 1] = '#';
	}
	for(int i = 1; i <= n; i++){
		len[i] = r > i ? min(len[(p << 1) - i], r - i) : 1;
		while(s[i - len[i]] == s[i + len[i]]) len[i]++;
		if(i + len[i] > r){
			r = i + len[i];
			p = i;
		}
		sum = (sum + (len[i] >> 1)) % MOD;
	}
	sum = (sum * (sum - 1)) >> 1;
	for(int i = 1; i <= n; i++){
		start[i - len[i] + 1]++;
		start[i | 1]--;
		end[i + len[i] - 1]++;
		end[(i - 1) | 1]--;
	}
	for(int i = 3; i <= n; i += 2)
		start[i] = (start[i] + start[i - 2]) % MOD;
	for(int i = n - 2; i >= 0; i -= 2)
		start[i] = (start[i] + start[i + 2]) % MOD;
	for(int i = n - 2; i >= 0; i -= 2)
		end[i] = (end[i] + end[i + 2]) % MOD;
	for(int i = 3; i < n; i += 2)
		sum = (sum - start[i] * end[i] % MOD + MOD) % MOD;
	printf("%I64d", sum);
	return 0;
}