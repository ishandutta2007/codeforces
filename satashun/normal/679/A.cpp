#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vp;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

bool ispr[110];

vector<int> pr;
vector<int> sq;

int cnt;

int main() {
    for (int i = 2; i <= 50; ++i) {
	if (ispr[i]) continue;
	pr.pb(i);
	for (int j = i * 2; j <= 50; j += i) ispr[j] = 1;
    }

    for (int x : pr) if (x * x <= 100) sq.pb(x * x);

    for (int x : pr) {
	printf("%d\n", x);
	fflush(stdout);

	char response[3];
	scanf("%s", response);

	if (strcmp(response, "yes") == 0) {
	    ++cnt;
	}
    }

    for (int x : sq) {
	printf("%d\n", x);
	fflush(stdout);

	char response[3];
	scanf("%s", response);

	if (strcmp(response, "yes") == 0) {
	    cnt = 2;
	}
    }

    if (cnt >= 2) puts("composite");
    else puts("prime");
    fflush(stdout);

    return 0;
}