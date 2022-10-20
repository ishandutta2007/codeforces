#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
typedef unsigned long long ull;
const ll LLmax = 0x1fffffffffffffffLL;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<typename T> inline void wr(T x){
	// puts("Write");
	static char stk[128];
	int top = 0;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

ll x0, Y0, ax, ay, bx, by;
ll xs, ys, t;
ll p[100], q[100];
bool check(ll st, ll l, ll r){
	// if(st == 4 && l == 4 && r == 3) puts("Checked");
	ull dis = abs(p[st] - xs) + abs(q[st] - ys);
	if(dis > (ull)t) return false;
	dis += abs(p[st] - p[l]) + abs(q[st] - q[l]);
	if(dis > (ull)t) return false;
	if(l <= r)
		for(int i=l+1; i<=r; i++){
			dis += abs(p[i] - p[i-1]) + abs(q[i] - q[i-1]);
			if(dis > (ull)t) return false;
		}
	else
		for(int i=l-1; i>=r; i--){
			dis += abs(p[i] - p[i+1]) + abs(q[i] - q[i+1]);
			if(dis > (ull)t) return false;
		}
	return true;
}

int main(){
	// File("b");
	// setbuf(stdout, NULL);
	gi(x0); gi(Y0); gi(ax); gi(ay); gi(bx); gi(by);
	gi(xs); gi(ys); gi(t);
	p[1] = x0; q[1] = Y0;
	int len = 0;
	for(int i=2; ; i++){
		if((LLmax - bx) / p[i-1] < ax || (LLmax - by) / q[i-1] < ay){
			len = i-1;
			break;
		}
		p[i] = p[i-1] * ax + bx;
		q[i] = q[i-1] * ay + by;
		// printf("%d: ", i); wr(p[i]); putchar(' '); wr(q[i]); putchar('\n');
	}
	int res = 0;
	for(int mid=1; mid<=len; mid++)
		for(int l=1; l<=len; l++)
			for(int r=1; r<=len; r++){
				if((l <= r && (mid < l || mid > r)) || (l > r && (mid < r || mid > l))) continue;
				if(check(mid, l, r)){
					// if(abs(r - l) + 1 == 1)
						// printf("[%d, %d] start %d\n", l, r, mid);
					upmax(res, abs(r - l) + 1);
				}
			}
	printf("%d\n", res);
	return 0;
}