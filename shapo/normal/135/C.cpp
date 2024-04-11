#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100500;

char s[MAXN];
int n;
int petya_moves, masha_moves;
int min_v[2], max_v[2];

bool
is_equal(char a, char b)
{
    return (a == '?' || a == b);
}

void
check00()
{
    if (min_v[1] <= masha_moves) {
        puts("00");
    }
}

void
check01and10()
{
    // 01
    if (s[n - 1] != '0') {
        if (s[n - 1] == '?') {
            --max_v[0];
            ++min_v[1];
        }
        if (masha_moves + 1 >= min_v[1] && masha_moves + 1 <= max_v[1]) {
            puts("01");
        }
        if (s[n - 1] == '?') {
            ++max_v[0];
            --min_v[1];
        }
    }
    // 10
    if (s[n - 1] != '1') {
        if (s[n - 1] == '?') {
            --max_v[1];
            ++min_v[0];
        }
        if (petya_moves + 1 >= min_v[0] && petya_moves + 1 <= max_v[0]) {
            puts("10");
        }
        if (s[n - 1] == '?') {
            ++max_v[1];
            --min_v[0];
        }
    }
}

void
check11()
{
    if (min_v[0] <= petya_moves) {
        puts("11");
    }
}

int
main()
{
    scanf(" %s", s);
    n = strlen(s);
    masha_moves = (n - 1) / 2, petya_moves = n / 2 - 1;
    for (int i = 0; i < 2; ++i) {
        min_v[i] = max_v[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            min_v[0]++, max_v[0]++;
        } else if (s[i] == '1') {
            min_v[1]++, max_v[1]++;
        } else {
            max_v[0]++, max_v[1]++;
        }
    }
    check00();
    check01and10();
    check11();
    return 0;
}