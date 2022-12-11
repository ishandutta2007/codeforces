#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1010;

char cardiogram[NMAX][NMAX];

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int curY = 0;
    vector<int> ySpots;
    vector<bool> isGoingUp;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < arr[i]; ++k) {
            isGoingUp.push_back(i % 2 == 0);
            ySpots.push_back(curY + (i % 2 == 0 ? 1 : -1) * k);
        }
        if (i % 2 == 0) curY += arr[i] - 1;
        else curY -= arr[i] - 1;
    }
    // cardiogram has length at most 1000, height at most 1000
    int base = *min_element(begin(ySpots), end(ySpots));
    int peak = *max_element(begin(ySpots), end(ySpots));
    // adjust so that peak => 0, base => (peak - base)
    // this function is peak - x!
    for (int i = 0; i < ySpots.size(); ++i) {
        cardiogram[peak - ySpots[i]][i] = isGoingUp[i] ? '/' : '\\';
    }
    for (int row = 0; row <= peak - base; ++row) {
        for (int col = 0; col < ySpots.size(); ++col) {
            if (cardiogram[row][col] == 0) printf(" ");
            else printf("%c", cardiogram[row][col]);
        }
        printf("\n");
    }
}