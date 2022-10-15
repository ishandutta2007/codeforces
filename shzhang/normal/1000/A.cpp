#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int s1, m1, l1;
int cnt1[5][2];

int s2, m2, l2;
int cnt2[5][2];

int n;

int abso(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[10];
        scanf("%s", s);
        if (strlen(s) == 1) {
            if (s[0] == 'S') s1++;
            if (s[0] == 'M') m1++;
            if (s[0] == 'L') l1++;
        } else {
            cnt1[strlen(s) - 1][s[strlen(s) - 1] == 'S' ? 1 : 0]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        char s[10];
        scanf("%s", s);
        if (strlen(s) == 1) {
            if (s[0] == 'S') s2++;
            if (s[0] == 'M') m2++;
            if (s[0] == 'L') l2++;
        } else {
            cnt2[strlen(s) - 1][s[strlen(s) - 1] == 'S' ? 1 : 0]++;
        }
    }
    int ans = 0;
    ans += abso(s1 - s2);
    ans += abso(m1 - m2);
    ans += abso(l1 - l2);
    for (int i = 1; i < 5; i++) {
        ans += abso(cnt1[i][0] - cnt2[i][0]);
        ans += abso(cnt1[i][1] - cnt2[i][1]);
    }
    ans /= 2;
    printf("%d", ans);
    return 0;
}