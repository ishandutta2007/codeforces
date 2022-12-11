#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 200;
int memo[NMAX][NMAX][2];

// 1 = P1 wins, -1 = P1 loses
int winner(int odds, int evens, int winParity) {
    if (memo[odds][evens][winParity] != 0) return memo[odds][evens][winParity]; 
    if (odds == 0 && evens == 0) return (winParity == 0 ? 1 : -1);
    bool canWin = false;
    if (odds > 0) { // Alice takes odd
        bool subcaseWin = true;
        // if alice can win in both of these, we good
            // Bob's move is to take odd
            // Bob's move is to take even
        if (odds == 1 && evens == 0 && winParity == 0) subcaseWin = false;
        if (odds > 1 && winner(odds - 2, evens, winParity ^ 1) == -1) subcaseWin = false;
        if (evens > 0 && winner(odds - 1, evens - 1, winParity ^ 1) == -1) subcaseWin = false;
        if (subcaseWin) canWin = true;
    }
    if (evens > 0) { // Alice takes even
        // if alice can win in both of these, we good
            // Bob's move is to take even
            // Bob's move is to take odd
        bool subcaseWin = true;
        if (odds == 0 && evens == 1 && winParity == 1) subcaseWin = false;
        if (odds > 0 && winner(odds - 1, evens - 1, winParity) == -1) subcaseWin = false;
        if (evens > 1 && winner(odds, evens - 2, winParity) == -1) subcaseWin = false;
        if (subcaseWin) canWin = true;
    }
    return (memo[odds][evens][winParity] = (canWin ? 1 : -1));
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int o = 0, e = 0;
        for (int v : arr) (v % 2 == 0 ? e : o)++;
        printf("%s\n", winner(o, e, 0) == 1 ? "Alice" : "Bob");
    }
}