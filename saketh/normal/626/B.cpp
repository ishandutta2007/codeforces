#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 205;

bool hit[MAXN][MAXN][MAXN][3];
bool cache[MAXN][MAXN][MAXN][3];

bool pos(int B, int G, int R, int goal) {
    if (hit[B][G][R][goal])
        return cache[B][G][R][goal];

    hit[B][G][R][goal] = true;
    bool &ans = cache[B][G][R][goal];

    // base case: only 1 color left
    if (B == 0 && G == 0) {
        return ans = (goal == 2);
    }
    if (B == 0 && R == 0) {
        return ans = (goal == 1);
    }
    if (G == 0 && R == 0) {
        return ans = (goal == 0);
    }

    ans = false;

    // do op 1
    if (B > 0 && G > 0) {
        ans |= pos(B - 1, G - 1, R + 1, goal);
    }
    if (B > 0 && R > 0) {
        ans |= pos(B - 1, G + 1, R - 1, goal);
    }
    if (G > 0 && R > 0) {
        ans |= pos(B + 1, G - 1, R - 1, goal);
    }

    // do op 2
    if (B >= 2) {
        ans |= pos(B - 1, G, R, goal);
    }
    if (G >= 2) {
        ans |= pos(B, G - 1, R, goal);
    }
    if (R >= 2) {
        ans |= pos(B, G, R - 1, goal);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    string str;

    cin >> N >> str;

    int B = 0, G = 0, R = 0;

    for (char c : str) {
        if (c == 'B') B++;
        else if(c == 'G') G++;
        else R++;
    }

    if (pos(B, G, R, 0)) {
        cout << 'B';
    }
    if(pos(B, G, R, 1)) {
        cout << 'G';
    }
    if(pos(B, G, R, 2)) {
        cout << 'R';
    }
    cout << "\n";

    return 0;
}