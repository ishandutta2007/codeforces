//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e4+5;

int T, n, p[N];
vector<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int a, int b, int c) {
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	scanf("%d", &a);
	if(a == -1) exit(0);
	return a;
}
void give(vector<int>& ans) {
	int sz = ans.size();
	printf("! %d", sz);
	for(auto i : ans) printf(" %d", i);
	printf("\n");
	fflush(stdout);
	ans.clear();
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int k = n / 3, Cg = 0, Ig = 0, Cm = 0, Im = 0; // (crewmate|imposter) (group|member)
		rep(i, 1, k) (p[i] = ask(3*i-2, 3*i-1, 3*i)) ? (Cg = i) : (Ig = i);
		int x = ask(3*Ig-1, 3*Ig, 3*Cg-2), y = ask(3*Ig, 3*Cg-2, 3*Cg-1);
		if(x) Im = 3 * Ig - 2, Cm = 3 * Cg - 2;
		else if(!y) Im = 3 * Ig, Cm = 3 * Cg;
		else Im = 3 * Ig - 1, Cm = 3 * Cg - 1;
		ans.push_back(Im);
		rep(i, 1, k) {
			if(i == Ig || i == Cg) {
				rep(j, 3*i-2, 3*i) {
					if(j == Im || j == Cm) continue;
					if(!ask(Im, Cm, j)) ans.push_back(j);
				}
			}
			else if(p[i]) {
				if(ask(Im, 3*i-2, 3*i-1)) {
					if(!ask(Im, Cm, 3*i)) ans.push_back(3*i);
				}
				else {
					if(!ask(Im, Cm, 3*i-2)) ans.push_back(3*i-2);
					else ans.push_back(3*i-1);
				}
			}
			else {
				if(ask(Cm, 3*i-2, 3*i-1)) {
					ans.push_back(3*i);
					if(!ask(Im, Cm, 3*i-2)) ans.push_back(3*i-2);
					else ans.push_back(3*i-1);
				}
				else {
					ans.push_back(3*i-2);
					ans.push_back(3*i-1);
					if(!ask(Im, Cm, 3*i)) ans.push_back(3*i);
				}
			}
		}
		give(ans);
	}
    return 0;
}