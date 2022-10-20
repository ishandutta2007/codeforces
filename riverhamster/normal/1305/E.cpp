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
const int N = 200005, Lim = 1000000000;
int a[N];

int main(){
	// File("e");
	int n, m, now = 0, sum = 0;
	gi(n); gi(m);
	if(m == 0){
		for(int i=Lim-n+1; i<=Lim; i++) wi(i), SP;
		EL;
		return 0;
	}
	int ls = 0;
	for(int i=1; i<=n; i++){
		now = (i - 1) / 2;
		if(sum + now >= m){
			int dec = sum + now - m;
			a[i] = i + dec * 2;
			sum = m;
			ls = i;
			break;
		}
		else a[i] = i, sum += now;
	}
	if(ls){
		// printf("ls = %d\n", ls);
		int now = a[ls] + a[ls - 1] + 1;
		if(now % (a[ls] + 1) == 0) ++now;
		for(int i=ls+1; i<=n; i++){
			a[i] = now;
			now += (a[ls] + 1);
		}
	}
	if(sum == m){
		for(int i=1; i<=n; i++) wi(a[i]), SP;
		EL;
	}
	else puts("-1");
	return 0;
}