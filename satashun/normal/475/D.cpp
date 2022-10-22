#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

int n, q;
int a[100010];
map<int, ll> m, zen;

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    m[a[0]] = zen[a[0]] = 1;

    for(int i = 1; i < n; ++i){
	map<int, ll> nxt;

	nxt[a[i]] = 1;
	for(auto it = m.begin(); it != m.end(); ++it)
	    nxt[__gcd(it->fi, a[i])] += it->se;
	m = nxt;

	for(auto it = m.begin(); it != m.end(); ++it)
	    zen[it->fi] += it->se;	
    }

    scanf("%d", &q);
    while(q--){
	int x;
	scanf("%d", &x);
	printf("%I64d\n", zen[x]);
    }
    return 0;

}