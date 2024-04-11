#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100005;
struct food{
	ll r, pr;
	int id;
}a[N];
bool cmp(food a, food b){
	if(a.pr == b.pr) return a.id < b.id;
	return a.pr < b.pr;
}
int idx[N];

template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	int n, m, low = 1, id;
	ll now, cnt;
	in(n); in(m);
	for(int i=1; i<=n; i++) in(a[i].r);
	for(int i=1; i<=n; i++) in(a[i].pr), a[i].id = i;
	sort(a+1, a+1+n, cmp);
	for(int i=1; i<=n; i++) idx[a[i].id] = i;
	for(int i=1; i<=m; i++){
		in(id); in(cnt);
		now = 0;
		id = idx[id];
		if(a[id].r >= cnt) a[id].r -= cnt, now = cnt * a[id].pr, cnt = 0;
		else{
			cnt -= a[id].r; now = a[id].r * a[id].pr; a[id].r = 0;
			for(; low<=n; low++){
				if(a[low].r >= cnt){
					a[low].r -= cnt;
					now += cnt * a[low].pr;
					cnt = 0;
					break;
				}
				else{
					cnt -= a[low].r; now += a[low].pr * a[low].r;
					a[low].r = 0;
				}
			}
			if(cnt != 0) now = 0;
		}
		cout << now << endl;
		// if(low > n) break;
	}
	return 0;
}