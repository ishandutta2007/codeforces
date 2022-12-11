#include <bits/stdc++.h>

using namespace std;

int getmatch(vector<int> &left, vector<int> &right, int c) {
    vector<int> colBal(c);
    for (int v : left) colBal[v]++;
    for (int v : right) colBal[v]--;
    vector<int> oddLeft, oddRight;
    for (int i = 0; i < c; ++i) {
        if (colBal[i] % 2 == 0) continue;
        if (colBal[i] > 0) oddLeft.push_back(i);
        else oddRight.push_back(i);
    }
    if (oddLeft.size() < oddRight.size()) return getmatch(right, left, c);
    // WLOG oddLeft is larger than oddRight
    int ans = 0;
    while (oddRight.size() > 0) {
        int ol = oddLeft.back(); oddLeft.pop_back();
        int orr = oddRight.back(); oddRight.pop_back();
        colBal[orr]++; colBal[ol]--; ++ans;
    }
    if (oddLeft.size() > 0) {
        vector<int> goodRight;
        for (int i = 0; i < c; ++i) if (colBal[i] < 0) goodRight.push_back(i);
        while (goodRight.size() > 0 && oddLeft.size() > 0) {
            int ol1 = oddLeft.back(); oddLeft.pop_back();
            int ol2 = oddLeft.back(); oddLeft.pop_back();
            int orr = goodRight.back();
            ans += 2;
            colBal[orr] += 2;
            colBal[ol1]--; colBal[ol2]--;
            if (colBal[orr] == 0) goodRight.pop_back();
        }
        while (oddLeft.size() > 0) {
            int ol1 = oddLeft.back(); oddLeft.pop_back();
            int ol2 = oddLeft.back(); oddLeft.pop_back();
            ans++;
            colBal[ol1]--; colBal[ol2]++;
        }
    }
    for (int v : colBal) ans += abs(v)/2;
    return ans;
}

int solve() {
    int n, l, r; scanf("%d %d %d", &n, &l, &r);
    vector<int> kulay(n);
    for (int i = 0; i < n; ++i) scanf("%d", &kulay[i]);
    for (int i = 0; i < n; ++i) --kulay[i];
    vector<int> left(begin(kulay), begin(kulay) + l), right(begin(kulay) + l, end(kulay));
    return getmatch(left, right, n);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}