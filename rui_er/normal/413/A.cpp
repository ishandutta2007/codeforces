//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, m, mn, mx, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d%d", &n, &m, &mn, &mx);
	int mnn = 2147483647, mxx = -2147483648;
	rep(i, 1, m) {
		scanf("%d", &a[i]);
		chkmin(mnn, a[i]);
		chkmax(mxx, a[i]);
	}
	if(mnn < mn || mxx > mx) return puts("Incorrect")&0;
	int nd = (mnn != mn) + (mxx != mx);
	puts(n-m<nd?"Incorrect":"Correct");
	return 0;
}