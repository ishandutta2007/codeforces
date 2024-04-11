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
int a[N], b[N];
char s[N];

int main(){
	// File("d");
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		scanf("%s", s + 1);
		for(int i=1; i<=n; i++){
			a[i] = i;
			b[i] = n - i + 1;
		}
		// for(int i=1; i<=n; i++) printf("%d ", a[i]);
		int left;
		s[n] = '<';
		s[0] = '<';
		for(int i=1; i<n; i++){
			if(s[i] == '>' && s[i-1] == '<') left = i;
			if(s[i+1] == '<' && s[i] == '>') reverse(a + left, a + i + 2);//, puts("Reversed");
		}
		int nL, nR, L = 0, R = -1;
		s[0] = s[n] = '>';
		for(int i=1; i<n; i++){
			if(s[i] == '<' && s[i-1] == '>') nL = i;
			if(s[i] == '<' && s[i+1] == '>'){
				nR = i;
				if(nR - nL > R - L) L = nL, R = nR;
			}
		}
		if(L){
			++R;
			// printf("L %d R %d\n", L, R);
			int lt = n - R;
			for(int i=L; i<=R; i++)
				b[i] = i - L + 1 + lt;
			for(int i=1; i<L; i++){
				if(s[i] == '<' && s[i-1] == '>') left = i;
				if(s[i+1] == '>' && s[i] == '<') reverse(b + left, b + i + 2);//, puts("Reversed");
			}
			for(int i=R+1; i<n; i++){
				if(s[i] == '<' && s[i-1] == '>') left = i;
				if(s[i+1] == '>' && s[i] == '<') reverse(b + left, b + i + 2);//, puts("Reversed");
			}
		}
		for(int i=1; i<=n; i++) printf("%d ", b[i]);
		puts("");
		for(int i=1; i<=n; i++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}