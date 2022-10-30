#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define rep(i, a, b) for (i=(a); i<(b); i++)
#define bpt(x) __builtin_popcount(x)
#define isset(x, y) ((x)&(1<<(y)))
#define pb push_back
#define beyond(u, v) (u<0 || v<0 || u>=N || v>=M)
#define x first
#define y second
#define eprint(...) fprintf(stderr, __VA_ARGS)

#define FILEIO(name) \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout);

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}
#define NN 111111
#define MM 33
char s[NN];
int str[NN], nn, vst[NN], flag;
int f(char c) {
	return c-'a';
}
int main() {
	int N;
	scanf("%d", &N);
	scanf("%s", s);
	int len=strlen(s), i, j;
	
	for(i=0; i<26; i++) {
		nn=0; ++flag;
		for(j=0; j<len; j++) {
			if(f(s[j])<i) str[nn++]=f(s[j]), vst[j]=flag;
		}
		
		int pas=-1, pre=-1;
		for(j=0; j<len; j++) {
			if(vst[j]==flag) pas=j;

			int id=f(s[j]);
			if(id==i) pre=j;
			if(pas+N==j) {
				if(pre<=pas) break;
				str[nn++]=i;
				pas=pre;
			}
		}
		if(j==len) break;
	}
	sort(str, str+nn);
	rep(i, 0, nn) printf("%c", str[i]+'a'); puts("");
	
	return 0;
}