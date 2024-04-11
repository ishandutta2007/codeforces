#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(vector<vector<char>> &eqd, vector<vector<char>> &eqr) {
    int h = eqd.size(), w = eqd[0].size();
    vector<vector<int>> ans(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        ans[i][0] = 1;
        for (int j = 1; j < w; ++j) ans[i][j] = (eqr[i][j-1] == 'N' ? 3 - ans[i][j-1] : ans[i][j-1]);
//        for (int j = 1; j < w; ++j) printf("cons %c\n", eqr[i][j-1]);
        if (i == 0) continue;
        int mismatch = 0;
        for (int j = 0; j < w; ++j) if ((eqd[i-1][j] == 'E') != (ans[i][j] == ans[i-1][j])) ++mismatch;
//        for (int j = 0; j < w; ++j) printf("yeet %c\n", eqd[i-1][j]);
        if (2 * mismatch > w) {
            for (int &v : ans[i]) v = 3 - v;
        }
    }
    return ans;
}

int main() {
    int h, w, k; scanf("%d %d %d", &h, &w, &k);
    vector<vector<char>> eqd(h, vector<char>(w)), eqr(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j + 1 < w; ++j) scanf(" %c", &eqr[i][j]);
        if (i + 1 < h) for (int j = 0; j < w; ++j) scanf(" %c", &eqd[i][j]);
//        printf("read row %d\n", i);
    }
    if (k == 1) {
        int violated = 0;
        for (vector<char> &x : eqd) for (char c : x) if (c == 'N') ++violated;
        for (vector<char> &x : eqr) for (char c : x) if (c == 'N') ++violated;
        // 1/4 * (2nm - n - m) >= violated
        if ((2 * h * w - h - w) >= violated * 4) {
            printf("YES\n");
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) printf("1 ");
                printf("\n");
            }
        } else {
            printf("NO\n");
        }
        return 0;
    }
    bool flipped = (h > w);
    vector<vector<int>> ans(h, vector<int>(w));
    if (!flipped) ans = generate(eqd, eqr);
    else {
//        printf("flipped\n");
        vector<vector<char>> teqd(w, vector<char>(h)), teqr(w, vector<char>(h));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j + 1 < w; ++j) teqd[j][i] = eqr[i][j];
            for (int j = 0; j < w; ++j) teqr[j][i] = eqd[i][j];
        }
        vector<vector<int>> tans = generate(teqd, teqr);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ans[i][j] = tans[j][i];
            }
        }
    }
    printf("YES\n");
    for (vector<int> &v : ans) {
        for (int x : v) printf("%d ", x);
        printf("\n");
    }
    return 0;
}