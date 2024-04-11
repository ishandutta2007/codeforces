#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
struct Pt{
	int id, x;
} a[105];
bool cmp(Pt a, Pt b){return a.x < b.x;}

int main(){
	// File("a");
	int n, x, sum = 0, allsum = 0, cnt = 0;
	in(n); in(x); allsum = x;
	for(int i=1; i<n; i++)
		in(a[i].x), a[i].id = i+1, allsum += a[i].x;
	sort(a+1, a+n, cmp);
	for(int i=1; i<n; i++){
		if(a[i].x * 2 > x) break;
		sum += a[i].x; ++cnt;
	}
	if((sum + x) * 2 <= allsum) puts("0");
	else{
		printf("%d\n%d ", cnt+1, 1);
		for(int i=1; i<=cnt; i++)
			printf("%d ", a[i].id);
		puts("");
	}
	return 0;
}