#include <iostream>
#include <vector>

using namespace std;

#define int long long

vector<int> lg;
vector<vector<int>> sparse_min(0, vector<int> (0));
vector<vector<int>> sparse_max(0, vector<int> (0));
vector<vector<int>> sparse_min_d(0, vector<int> (0));

int get_min(int l, int r) {
    int p = lg[r - l];
    return min(sparse_min[l][p], sparse_min[r - (1 << p)][p]);
}

int get_max(int l, int r) {
    int p = lg[r - l];
    return max(sparse_max[l][p], sparse_max[r - (1 << p)][p]);
}

int get_min_d(int l, int r) {
	int p = lg[r - l];
    return min(sparse_min_d[l][p], sparse_min_d[r - (1 << p)][p]);
}

int32_t main() {
    int n, s, len;
    cin >> n >> s >> len;
    vector<int> in(n);
    lg.assign(n + 2, 0);
    int cur = 1, lol = 0;
    for(int i = 1; i < n + 2; i ++) {
        while(cur * 2 <= i) {
            lol ++;
            cur *= 2;
        }
        lg[i] = lol;
    }
    sparse_min.assign(n, vector<int> (17));
    sparse_max.assign(n, vector<int> (17));
    for(int i = 0; i < n; i ++) {
        cin >> in[i];
        sparse_min[i][0] = in[i];
        sparse_max[i][0] = in[i];
    }
    for(int i = 0; i < 16; i ++) {
        for(int l = 0; l + (1 << (i + 1)) <= n; l ++) {
            sparse_min[l][i + 1] = min(sparse_min[l][i], sparse_min[l + (1 << i)][i]);
            sparse_max[l][i + 1] = max(sparse_max[l][i], sparse_max[l + (1 << i)][i]);
        }
    }
    sparse_min_d.assign(n + 1, vector<int> (17, 1e9));
    vector<int> d(n + 1, 1e9);
    d[0] = 0;
    sparse_min_d[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
    	int l = 1, r = i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get_max(i - m, i) - get_min(i - m, i) <= s) {
                l = m;
            } else {
                r = m;
            }
        }
        if (len > l) {
            d[i] = 1e9;
        } else {
    	    d[i] = get_min_d(i - l, i - len + 1) + 1;
    	}
        sparse_min_d[i][0] = d[i];
        for (int j = 1; j < 17; ++j) {
            if (i + 1 - (1 << j) < 0) {
                break;
            }
            sparse_min_d[i + 1 - (1 << j)][j] = min(sparse_min_d[i + 1 - (1 << j)][j - 1],
                                                    sparse_min_d[i + 1 - (1 << (j - 1))][j - 1]);
        }
    }
    if (d[n] >= 1e9) {
        d[n] = -1;
    }
    cout << d[n] << endl;
}