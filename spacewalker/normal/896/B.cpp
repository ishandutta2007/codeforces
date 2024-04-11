#include <bits/stdc++.h>

using namespace std;

vector<int> cards;

bool hasWon() {
    for (int i = 0; i < cards.size(); ++i) {
        if (cards[i] == -1) return false;
        if (i > 0 && cards[i-1] > cards[i]) return false;
    }
//    fprintf(stderr, "SOL: Win detected\n");
    return true;
}

bool placeAt(int num, int i) {
    assert(0 <= i && i < cards.size());
    printf("%d\n", i + 1);
    cards[i] = num;
    fflush(stdout);
    return hasWon();
}

int main() {
    int n, m, c; scanf("%d %d %d", &n, &m, &c);
    cards.assign(n, -1); 
    int front = 0, back = n - 1;
    for (int i = 0; i < m; ++i) {
        int num; scanf("%d", &num);
        if (2 * num <= c) {
            int pi = front;
            while (pi > 0 && cards[pi - 1] > num) --pi;
            placeAt(num, pi);
            if (pi == front) ++front;
        } else {
            int pi = back;
            while (pi < n - 1 && num > cards[pi + 1]) ++pi;
            placeAt(num, pi);
            if (pi == back) --back;
        }
        if (hasWon()) return 0;
        assert(i < m - 1);
    }
    return 0;
}