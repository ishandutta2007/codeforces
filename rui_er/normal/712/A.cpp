//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) printf("%d%c", a[i]+a[i+1], " \n"[i==n]);
	return 0;
}