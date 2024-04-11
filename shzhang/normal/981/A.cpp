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
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

char s[55];

bool palin(int l, int r)
{
    for (int i = l; i <= r; i++) {
        if (s[i] != s[r+l-i]) return false;
    }
    return true;
}

int main()
{
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        for (int j = i; s[j]; j++) {
            if (!palin(i, j)) ans = max(ans, j - i + 1);
        }
    }
    printf("%d", ans);
    return 0;
}