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

int n, k;
deque<int> q[100010];
int wh[100010];
int ret;
vector<pii> vec;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    ret = n - 1;

    rep(i, k) {
	int l;
	cin >> l;
	q[i].resize(l);

	rep(j, l) {
	    int x;
	    cin >> x;
	    q[i][j] = x;
	    wh[x] = i;
	}
/*
	rep(j, l-1) {
	    if (q[i][j+1] - q[i][j] != 1) {
		//++ret;
		ret += l - 1 - j;
		break;
	    }
	}
*/
	ret += l - 1;
	if (q[i][0] == 1) {
	    int j = 0;
	    while (j < l-1 && q[i][j+1] - q[i][j] == 1) {
		++j;
		ret -= 2;
	    }
	}
/*
	int st = q[i][0];
	for (int j = 1; j < l; ++j) {
	    if (q[i][j] == st + 1) ++st;
	    else {
		vec.eb(st, q[i][j-1]);
		st = q[i][j];
	    }
	}

	vec.eb(st, q[i][l-1]);*/
    }
    
    //sort(vec.begin(), vec.end());
    /*
    int cur = n;
    while (cur >= 1) {
	int p = wh[cur];

	int ad = 0;
	if (q[p].size() > 1) {
	    q[p].pop_back();
	    --cur;
	    ++ad;
	}

	if (cur == 0) break;
	ret += ad;
    }
    */
    cout << ret  << endl;
    
    //for (auto &p : vec) cout << p.fi << " " << p.se << endl;
    return 0;
}