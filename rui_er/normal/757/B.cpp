//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, a[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		for(int j=1;j*j<=a[i];j++) {
			if(!(a[i] % j)) {
				++buc[j];
				if(j * j < a[i]) ++buc[a[i]/j];
			}
		}
	}
	printf("%d\n", max(1, *max_element(buc+2, buc+N)));
	return 0;
}