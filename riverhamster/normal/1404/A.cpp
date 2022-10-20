#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 300005;

char s[N];
char a[N];

int main(){
  // File("a");
  int T;
  gi(T);
  while(T--){
    int n, k;
    gi(n); gi(k);
    scanf("%s", s);
    fill(a, a+k, 0);
    bool flag = true;
    for(int i=0; i<n; i++){
      if(s[i] == '?') continue;
      if(a[i % k]){
        if(a[i%k] == s[i]) continue;
        puts("NO");
        flag = false;
        break;
      }
      a[i%k] = s[i];
    }
    if(!flag) continue;
    int sum = 0, c = 0;
    for(int i=0; i<k; i++){
      if(!a[i]) ++c;
      if(a[i]=='1') ++sum;
    }
    if(sum <= k / 2 && (sum + c) >= k / 2) puts("YES");
    else puts("NO");
  }
	return 0;
}