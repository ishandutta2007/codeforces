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

int n, d, h;

int main() {
    cin >> n >> d >> h;

    if (d > 2 * h || (d == 1 && h == 1 && n != 2)) {
	puts("-1");
	return 0;
    }

    int now = 1;

    rep(i, h) {
	printf("%d %d\n", now, now + 1);
	++now;
    }

    if (d > h) {
	now++;
	printf("%d %d\n", 1, now);

	rep(i, d - h - 1) {
	    printf("%d %d\n", now, now + 1);
	    ++now;
	}

	while (now < n) {
	    ++now;
	    printf("%d %d\n", 1, now);	
	}

    } else { // d 
	while (now < n) {
	    ++now;
	    printf("%d %d\n", 2, now);
	}
    }


    return 0;
}