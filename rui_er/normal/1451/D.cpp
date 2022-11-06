//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, d, k, mx[N], mx2[N], ans;
bool ok(int x, int y) {
	double dis = sqrt(1.0*x*x+1.0*y*y);
	return dis - d < 1e-7;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		fil(mx, 0); fil(mx2, 0); ans = 0;
		scanf("%d%d", &d, &k);
		int u = 0, v = d;
		while(u <= d) {
			if(ok(u, v)) mx[u++] = v;
			else --v;
		}
		for(int i=0;i<=d;i+=k) ans = max(ans, mx2[i] = i / k + mx[i] / k);
		puts((ans&1)?"Ashish":"Utkarsh");
	}
	return 0;
}