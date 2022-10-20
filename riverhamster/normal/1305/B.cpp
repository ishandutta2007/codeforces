#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 1005;
char s[N], ns[N];
bool del[N];
vector<int> op[N];

int main(){
	// File("b");
	scanf("%s", s);
	int n = strlen(s);
	bool flag = true;
	int opt = 0;
	while(flag){
		int l = 0, r = n - 1, cnt = 0;
		while(l < r){
			if(s[l] == '(' && s[r] == ')'){
				del[l] = true; del[r] = true;
				cnt += 2;
				++l; --r;
			}
			else if(s[l] == ')'){
				++l;
			}
			else if(s[r] == '(') --r;
		}
		// printf("cnt = %d\n", cnt);
		if(!cnt) break;
		++opt;
		for(int i=0; i<n; i++)
			if(del[i]) op[opt].push_back(i + 1);
		int nn = 0;
		for(int i=0; i<n; i++){
			if(!del[i]){
				ns[nn] = s[i];
				++nn;
			}
		}
		ns[nn] = 0;
		copy(ns, ns+nn, s);
		n = nn;
	}
	printf("%d\n", opt);
	for(int i=1; i<=opt; i++){
		printf("%lu\n", op[i].size());
		for(int v : op[i])
			printf("%d ", v);
		EL;
	}
	return 0;
}