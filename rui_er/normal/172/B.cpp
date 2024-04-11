//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int rnds;
map<int, int> mp;
namespace Rand {
	int a, b, m, x;
	void srand() {scanf("%d%d%d%d", &a, &b, &m, &x);}
	int rand() {return x = (a * x + b) % m;}
}

int main() {
	Rand::srand();
	loop {
		++rnds;
		int qwq = Rand::rand();
		if(mp[qwq]) return printf("%d\n", rnds-mp[qwq]), 0;
		mp[qwq] = rnds;
	}
	return 0;
}