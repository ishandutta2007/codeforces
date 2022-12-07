#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int hp1, hp2, atk1, atk2, def1, def2;
int h, a, d;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> hp1 >> atk1 >> def1;
	cin >> hp2 >> atk2 >> def2;
	cin >> h >> a >> d;

	int ans = 1e9;

	for (int ia = 0; ia <= 305; ia++) for (int ib = 0; ib <= 205; ib++) {
		int hp = hp1;
		int atk = atk1 + ia;
		int def = def1 + ib;

		if (atk <= def2) continue;

		int HP = hp2;
		int ATK = atk2;
		int DEF = def2;

		while (HP > 0) {
			HP -= max(0, atk - DEF);
			hp -= max(0, ATK - def);
		}

		int cost = ia * a + ib * d;
		if (hp <= 0) cost += (-hp + 1) * h;
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}