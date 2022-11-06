//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, x, lst = -1, diff = -1;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%1d", &x);
		if(x) {
			if(lst == -1) lst = i;
			else if(diff == -1) {
				diff = i - lst;
				lst = i;
			}
			else if(i - lst == diff) lst = i;
			else return puts("NO")&0;
		}
	}
	puts("YES");
	return 0;
}