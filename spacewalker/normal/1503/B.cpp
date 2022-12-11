#include <bits/stdc++.h>

using namespace std;

void place(int b, int i, int j) {
    printf("%d %d %d\n", b, i + 1, j + 1);
    fflush(stdout);
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> onePattern, twoPattern;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ((i + j) % 2 == 0 ? onePattern : twoPattern).emplace_back(i, j);
        }
    }
    auto autoPlace = [&] (int b) {
        bool placeFromOne = b == 1 || (b == 3 && !onePattern.empty());
        if (placeFromOne) {
            auto [i, j] = onePattern.back();
            place(b, i, j);
            onePattern.pop_back();
        } else {
            auto [i, j] = twoPattern.back();
            place(b, i, j);
            twoPattern.pop_back();
        }
    };
    for (int i = 0; i < n * n; ++i) {
        int a; scanf("%d", &a);
        if (!onePattern.empty() && !twoPattern.empty()) {
            if (a == 1) autoPlace(2);
            else autoPlace(1);
        } else if (onePattern.empty()) {
            if (a == 2) autoPlace(3);
            else autoPlace(2);
        } else if (twoPattern.empty()) {
            if (a == 1) autoPlace(3);
            else autoPlace(1);
        }
    }
}