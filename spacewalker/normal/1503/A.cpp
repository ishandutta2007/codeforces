#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 300010;

char strng[NMAX];
char ans1[NMAX], ans2[NMAX];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        scanf("%s", strng);
        vector<int> onePos, zeroPos;
        for (int i = 0; i < n; ++i) (strng[i] == '1' ? onePos : zeroPos).push_back(i);
        if (onePos.size() < 2 || onePos.front() != 0 || onePos.back() != n -1 || onePos.size() % 2 == 1) {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < onePos.size() / 2; ++i) {
            ans1[onePos[i]] = ans2[onePos[i]] = '(';
        }
        for (int i = onePos.size() / 2; i < onePos.size(); ++i) {
            ans1[onePos[i]] = ans2[onePos[i]] = ')';
        }
        for (int i = 0; i < zeroPos.size(); ++i) {
            ans1[zeroPos[i]] = '(';
            ans2[zeroPos[i]] = ')';
            if (i % 2 == 1) swap(ans1[zeroPos[i]], ans2[zeroPos[i]]);
        }
        ans1[n] = ans2[n] = 0;
        printf("YES\n");
        printf("%s\n%s\n", ans1, ans2);
    }
    return 0;
}