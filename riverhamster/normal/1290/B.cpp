#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 200005;
char s[N];
int sum[N][26];

int main(){
	// File("b");
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i=1; i<=n; i++){
		copy(sum[i-1], sum[i-1]+26, sum[i]);
		++sum[i][s[i] - 'a'];
	}
	int Q; gi(Q);
	while(Q--){
		int l, r;
		gi(l); gi(r);
		int cnt = 0;
		for(int i=0; i<26; i++){
			if(sum[l-1][i] != sum[r][i]) ++cnt;
		}
		if(cnt == 1){
			if(r - l) puts("No");
			else puts("Yes");
		}
		else if(cnt == 2){
			if(s[l] == s[r]) puts("No");
			else puts("Yes");
		}
		else puts("Yes");
	}
	return 0;
}