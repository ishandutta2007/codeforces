#include <bits/stdc++.h>

using namespace std;

#define maxn 200010
#define pii pair<int, int>
#define ti tuple<int, int, int>

vector<vector<ti>> ch(maxn);
vector<vector<int>> re(maxn);
int seg[maxn*4][101];
int nums[maxn];

void cquery(int spot, int x, int y, int ss, int se, int si) {
	if (spot < ss || spot > se || ss > se) return;
	if (ss == se) {
		for (int i = 1; i <= 100; i++) {
			seg[si][i] = i;
		}
		seg[si][x] = y;
		// cout << "down here  " << seg[si][1] << endl;
		return;
	}
	int mid = (ss+se)/2;
	cquery(spot, x, y, ss, mid, si*2+1);
	cquery(spot, x, y, mid+1, se, si*2+2);
	// cout << "just checking  " << seg[si*2+1][1] << "  "<< ss << "  " << se << endl;
	for (int i = 1; i <= 100; i++) {
		// cout << "this part  " << i << " - " << seg[si*2+1][i] << endl;
		seg[si][i] = seg[si*2+2][seg[si*2+1][i]];
	}
}

void revert(int spot, int ss, int se, int si) {
	if (spot < ss || spot > se || ss > se) return;
	if (spot == ss && spot == se) {
		for (int i = 1; i <= 100; i++) {
			seg[si][i] = i;
		}
		return;
	}
	int mid = (ss+se)/2;
	revert(spot, ss, mid, si*2+1);
	revert(spot, mid+1, se, si*2+2);
	for (int i = 1; i <= 100; i++) {
		seg[si][i] = seg[si*2+2][seg[si*2+1][i]];
	}

}

void buildtree(int ss, int se, int si) {
	for (int i = 1; i <= 100; i++) {
		seg[si][i] = i;
	}
	if (ss == se) return;
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int q;
	// buildtree(0, q, 0);
	// cout << "begin  " << seg[0][1] << endl;
	cin >> q;
	buildtree(0, q, 0);
	int l, r, x, y;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> x >> y;
		ch[l].push_back(make_tuple(x, y, i));
		re[r+1].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < ch[i].size(); j++) {
			cquery(get<2>(ch[i][j]), get<0>(ch[i][j]), get<1>(ch[i][j]), 0, q, 0);
		}
		for (int j = 0; j < re[i].size(); j++) {
			revert(re[i][j], 0, q, 0);
		}
		// cout << "now it is " << seg[0][1] << endl;
		// cout << i << "   -- " << nums[i] << "   " << seg[0][nums[i]] << endl;
		cout << seg[0][nums[i]] << " ";
	}
	cout << endl;
}