#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A, B;

vector<int> BposInA;

bool answerWorks(vector<int> &ans) {
    vector<int> rowPerm(A.size());
    iota(begin(rowPerm), end(rowPerm), 0);
    for (int c : ans) {
        stable_sort(begin(rowPerm), end(rowPerm), [&] (int i, int j) {return A[i][c] < A[j][c];});
    }
    for (int i = 0; i < A.size(); ++i) if (A[rowPerm[i]] != B[i]) return false;
    return true;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    A.assign(n, vector<int>(m));
    B = A;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &A[i][j]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &B[i][j]);
    if (A == B) {
        printf("0\n");
        return 0;
    }
    BposInA.assign(n, -1); // TODO compute this; if this stays -1 for some row output -1 and exit

    auto rowsSorted = [&] (vector<vector<int>> &X) {
        int n = X.size();
        vector<int> ans(n);
        iota(begin(ans), end(ans), 0);
        stable_sort(begin(ans), end(ans), [&] (int i, int j) {return X[i] < X[j];});
        return ans;
    };

    vector<int> ars = rowsSorted(A), brs = rowsSorted(B);
    for (int i = 0; i < n; ++i) {
        if (A[ars[i]] != B[brs[i]]) {
            printf("-1\n");
            return 0;
        } else {
            BposInA[brs[i]] = ars[i];
        }
    }
    vector<int> notFollowedAlongCol(m, 0);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i + 1 < n; ++i) {
            if (B[i][j] > B[i+1][j]) ++notFollowedAlongCol[j];
        }
    }
    vector<bool> followConstraintUnder(n-1, true);
    queue<int> readyToSort;
    vector<int> answer;
    auto removeViolatorAt = [&] (int j) {
        if (notFollowedAlongCol[j] == 1) readyToSort.push(j);
        --notFollowedAlongCol[j];
    };
    for (int i = 0; i < m; ++i) if (notFollowedAlongCol[i] == 0) readyToSort.push(i);
    while (!readyToSort.empty()) {
        bool alreadyGood = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (followConstraintUnder[i] && BposInA[i] > BposInA[i+1]) alreadyGood = false;
        }
        if (alreadyGood) break;
        int cts = readyToSort.front(); readyToSort.pop();
//        printf("testing %d\n", cts);
        answer.push_back(cts);
        for (int i = 0; i + 1 < n; ++i) {
            if (!followConstraintUnder[i]) continue;
//            printf("comparing values %d %d\n", B[i][cts], B[i+1][cts]);
            if (B[i][cts] < B[i+1][cts]) { // clear this row
                followConstraintUnder[i] = false;
                for (int j = 0; j < m; ++j) if (B[i][j] > B[i+1][j]) removeViolatorAt(j);
            }
        }
    }
    // validate if it works
    reverse(begin(answer), end(answer));
    if (answerWorks(answer)) {
        printf("%lu\n", answer.size());
        for (int v : answer) printf("%d ", v + 1);
        printf("\n");
    } else printf("-1\n");
}