//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1<<16;

int n, x[N+5];
int interact(int op, int x, int y) {
	printf("%s %d %d\n", op==1?"AND":(op==2?"OR":"XOR"), x, y);
	fflush(stdout); int res; scanf("%d", &res); return res;
}

int main() { // a|b-a&b=a^b a&b+a|b=a+b a1+a2=(a1|a2)*2-(a1^a2)
	scanf("%d", &n);
	rep(i, 2, n) x[i] = interact(3, 1, i);
	int _12 = interact(2, 1, 2), _13 = interact(2, 1, 3), _23 = interact(2, 2, 3);
	int s12 = _12 * 2 - x[2], s13 = _13 * 2 - x[3], s23 = _23 * 2 - (x[2] ^ x[3]);
	int s123 = (s12 + s13 + s23) / 2;
	printf("! %d %d %d ", s123-s23, s123-s13, s123-s12);
	rep(i, 4, n) printf("%d ", (s123-s23)^x[i]); puts(""); fflush(stdout);
	return 0;
}