#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
char s[111];

bool
can()
{
    for (int i = 0; i < n; ++i) {
        for (int diff = 1; diff * 4 + i < n; ++diff) {
            int cnt = 0;
            for (int k = 0; k < 5; ++k) {
                if (i + diff * k < n && s[i + diff * k] == '*') {
                    ++cnt;
                }
            }
            if (cnt == 5) {
                return true;
            }
        }
    }
    return false;
}

int
main()
{
    scanf("%d %s", &n, s);
    if (can()) {
        puts("yes");
    } else {
        puts("no");
    }
    return 0;
}