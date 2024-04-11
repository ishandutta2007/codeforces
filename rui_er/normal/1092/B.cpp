//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int n, a[105], s;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	rep(i, 1, n) if(i & 1) s += a[i+1] - a[i];
	printf("%d\n", s);
	return 0;
}