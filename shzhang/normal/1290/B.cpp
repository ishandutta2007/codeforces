#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

int psum[26][200005];
char s[200005]; int q;

int main()
{
    scanf("%s", s + 1);
    scanf("%d", &q);
    for (int i = 1; s[i]; i++) {
        psum[s[i] - 'a'][i] = 1;
    }
    for (int chr = 0; chr < 26; chr++) {
        for (int i = 1; s[i]; i++) {
            psum[chr][i] += psum[chr][i-1];
        }
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r) {
            printf("Yes\n"); continue;
        }
        if (r - l + 1 == 2) {
            printf(s[l] == s[r] ? "No\n" : "Yes\n"); continue;
        }
        if (s[l] != s[r]) {
            printf("Yes\n"); continue;
        }

        int found = 0;
        for (int chr = 0; chr < 26; chr++) {
            if (chr + 'a' != s[l])
                found += min(psum[chr][r] - psum[chr][l-1], 1);
        }
        printf(found < 2 ? "No\n" : "Yes\n");
    }
    return 0;
}