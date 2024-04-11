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

ll n, T;
ll t[105], l[105], r[105];
ll rL[105], rR[105];
ll last = 0;

int main(){
	// File("c");
	int Test;
	gi(Test);
	while(Test--){
		last = 0;
		gi(n); gi(T);
		// ll tm = 0;
		bool flag = true;
		rL[0] = rR[0] = T;
		for(int i=1; i<=n; i++){
			gi(t[i]); gi(l[i]); gi(r[i]);
			rL[i] = rL[i-1] - (t[i] - t[i-1]);
			rR[i] = rR[i-1] + (t[i] - t[i-1]);
			if(rR[i] < l[i] || rL[i] > r[i]) flag = false;
			upmin(rR[i], r[i]);
			upmax(rL[i], l[i]);
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}