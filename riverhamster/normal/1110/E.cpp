#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 100005;
int a[N], b[N], d1[N], d2[N];

int main(){
	// freopen("cf1110e.in", "r", stdin);
	// freopen("cf1110e.out", "w", stdout);
	int n;
	in(n);
	for(int i=1; i<=n; i++)
		in(a[i]);
	for(int i=1; i<=n; i++)
		in(b[i]);
	if(a[1] != b[1] || a[n] != b[n]) puts("No");
	else{
		for(int i=1; i<n; i++)
			d1[i] = a[i+1] - a[i], d2[i] = b[i+1] - b[i];
		sort(d1+1, d1+n); sort(d2+1, d2+n);
		bool flag = true;
		for(int i=1; i<n; i++)
			if(d1[i] != d2[i]){
				puts("No");
				flag = false;
				break;
			}
		if(flag) puts("Yes");
	}
	return 0;
}