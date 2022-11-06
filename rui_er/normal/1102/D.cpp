//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5; 

int n, k, buc[3];
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%s", &n, s+1);
	k = n / 3;
	rep(i, 1, n) ++buc[s[i]-'0'];
	if(buc[0] > k) {
		per(i, n, 1) {
			if(s[i] == '0') {
				int t = buc[2] < k ? 2 : 1;
				s[i] = t + '0';
				++buc[t]; --buc[0];
				if(buc[0] == k) break;
			}
		}
	}
	if(buc[2] > k) {
		rep(i, 1, n) {
			if(s[i] == '2') {
				int t = buc[0] < k ? 0 : 1;
				s[i] = t + '0';
				++buc[t]; --buc[2];
				if(buc[2] == k) break;
			}
		}
	}
	if(buc[1] > k) {
		if(buc[0] < k) {
			rep(i, 1, n) {
				if(s[i] == '1') {
					s[i] = '0';
					++buc[0]; --buc[1];
					if(buc[0] == k) break;
				}
			}
		}
		if(buc[2] < k) {
			per(i, n, 1) {
				if(s[i] == '1') {
					s[i] = '2';
					++buc[2]; --buc[1];
					if(buc[2] == k) break;
				}
			}
		}
	}
	printf("%s\n", s+1);
	return 0;
}