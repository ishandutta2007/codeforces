#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 200005;
struct pt{
	int x, y;
}a[N];
bool cmpx(pt a, pt b){return a.x < b.x;}
bool cmpy(pt a, pt b){return a.y < b.y;}

int tr[N], n;
int pcnt[N], dcnt[N];
int ask(int x){int ans=0; for(int i=x; i; i-=i&(-i)) ans += tr[i]; return ans;}
void add(int p){for(int i=p; i<=n; i+=i&(-i)) ++tr[i];}

int main(){
	// File("cf1190d");
	// setbuf(stdout, NULL);
	int last = 0, now = 0;
	ll totx;
	in(n);
	for(int i=1; i<=n; i++) in(a[i].x), in(a[i].y);
	sort(a+1, a+1+n, cmpx);
	for(int i=1; i<=n; i++){
		now = a[i].x;
		if(a[i].x != last) a[i].x = a[i-1].x + 1;
		else a[i].x = a[i-1].x;
		++pcnt[a[i].x];
		last = now;
	}
	totx = a[n].x;
	ll res = totx * (totx + 1) / 2;
	sort(a+1, a+1+n, cmpy);
	// printf("points after Discretization x:\n");
	// for(int i=1; i<=n; i++) printf("(%d, %d) ", a[i].x, a[i].y);
	// puts("");
	// printf("At first res = %lld\n", res);
	vector<int> del;
	for(int i=1; i<=n; i++){
		if(a[i+1].y == a[i].y){
			del.push_back(a[i].x); ++dcnt[a[i].x];
			if(dcnt[a[i].x] == pcnt[a[i].x]) add(a[i].x);
		} 
		else{
			del.push_back(a[i].x); ++dcnt[a[i].x];
			if(dcnt[a[i].x] == pcnt[a[i].x]) add(a[i].x);
			ll totp = totx - ask(totx);
			res += totp * (totp + 1) / 2;
			// printf("totp = %lld res += %lld\n", totp, totp * (totp+1) / 2);
			del.push_back(0); del.push_back(totx + 1);
			sort(del.begin(), del.end());
			int S = del.size(); ll cnt = 0;
			for(int i=0; i<S-1; i++){
				cnt = del[i+1] - del[i] - 1 - (ask(del[i+1] - 1) - ask(del[i]));
				// printf("between (%d, %d): %lld vaild elements.\n", del[i+1], del[i], cnt);
				res -= cnt * (cnt+1) / 2;
			}
			del.clear();
		}
	}
	printf("%lld\n", res);
	return 0;
}