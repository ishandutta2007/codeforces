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

bool is_leap(int y)
{
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    return (y % 4 == 0);
}

int y;
int u;
bool flag;

int main() {
    cin >> y;
    flag = is_leap(y);

    ++y;

    while (true) {
	int m = (365 + is_leap(y)) % 7;
	u = (u + m) % 7;

	if (is_leap(y) == flag && u == 0) break;
	++y;
    }
    cout << y << endl;

    return 0;
}