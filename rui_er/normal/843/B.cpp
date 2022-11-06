//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 5e4+5, inf = 0x3f3f3f3f;

int n, front, x, ans = -inf, nxt;
vector<int> interact(int _) {
	printf("? %d\n", _);
	fflush(stdout);
	int a, b;
	scanf("%d%d", &a, &b);
	return vector<int>({a, b});
}
void give(int _) {
	printf("! %d\n", _);
	fflush(stdout);
}

int seed, seed2;
void srand(int x, int y) {seed = x; seed2 = y;}
int frand() {return (seed *= 19260817) += ((seed2 += 114514) ^= 1919810);}
int rand() {int res = frand(); while(res <= 0) res += n; return res;}

int main() {
//	srand(time(0));
//	srand(rand()); srand(rand()+19849);
	srand(998244353, 1000000007);
//	rep(i, 1, 100) printf("%d %d %d\n", seed, seed2, rand());
	scanf("%d%d%d", &n, &front, &x);
	nxt = front;
	rep(i, 1, min(n, 1000)-1) {
		int pos = rand() % n + 1;
		vector<int> res = interact(pos);
		if(res[0] <= x && res[0] > ans) nxt = res[1], ans = res[0];
	}
	if(ans == x) return give(x), 0;
	rep(i, 1, 1000) {
		if(nxt == -1) break;
		vector<int> res = interact(nxt);
		if(res[0] >= x) return give(res[0]), 0;
		ans = res[0]; nxt = res[1];
	}
	give(ans>=x?ans:-1);
	return 0;
}