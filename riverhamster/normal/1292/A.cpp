#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 100005;
bool f[2][N];
int cnt = 0;

int main(){
	// File("a");
	int n, q;
	gi(n); gi(q);
	for(int i=1; i<=q; i++){
		int x, y; gi(x); gi(y);
		x -= 1;
		f[x][y] = !f[x][y];
		// bool flag = true;
		if(f[x][y]) cnt += f[x^1][y] + f[x^1][y-1] + f[x^1][y+1];
		else cnt -= f[x^1][y] + f[x^1][y+1] + f[x^1][y-1];
		if(cnt == 0) puts("Yes");
		else puts("No");
	}
	return 0;
}