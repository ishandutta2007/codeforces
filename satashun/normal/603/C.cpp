#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int p[1000010];
/*
int grundy(int x)
{
    if (p[x] != -1) return p[x];
    set<int> s;

    if (x > 0 && x % 2 == 0) {
	s.insert(grundy(x/2));
    } 

    if (x > 0) s.insert(grundy(x-1));

    for (int i=0;;++i) if(!s.count(i)) return p[x]=i;
}
*/

int n, k;
int a[100010];

//k:odd
int og(int x)
{
    if (x == 1 || x == 3) return 1;
    if (x == 0 || x & 1) return 0;

    set<int> s;

    s.insert(og(x / 2));
    s.insert(og(x - 1));

    for (int i = 0; ; ++i) if (!s.count(i)) return i;
}

//k:even
int eg(int x)
{
    if (x == 2) return 2;
    if (x == 1) return 1;
    if (x == 0 || x & 1) return 0;
    return 1;
}

int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    if (k & 1) {
	int res = 0;
	rep(i, n) res ^= og(a[i]);
	if (res == 0) cout << "Nicky\n";
	else cout << "Kevin\n";
    } else {
	int res = 0;
	rep(i, n) res ^= eg(a[i]);
	if (res == 0) cout << "Nicky\n";
	else cout << "Kevin\n";
    }

    return 0;
}