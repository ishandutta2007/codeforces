#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <cstddef>
#include <cassert>

using namespace std;

constexpr size_t MAXN = (size_t) 2e5 + 5;

int cnt[26];
char str[MAXN];

void PrintZero(int first)
{
    putchar(first + 'a');
    for (int i = 0; i < 26; i++) {
        if (i != first) {
            for (int j = 0; j < cnt[i]; j++) {
                putchar(i + 'a');
            }
        }
    }
}

void SingleFirst(int first)
{
    putchar(first + 'a');

    int second = -1, third = -1;

    for (int i = first + 1; i < 26; i++) {
        if (cnt[i] > 0) {
            if (second == -1) {
                second = i;
            } else if (third == -1) {
                third = i;
                break;
            }
        }
    }

    if (third == -1) {
        for (int j = 0; j < cnt[second]; j++) {
            putchar(second + 'a');
        }
        for (int j = 0; j < cnt[first] - 1; j++) {
            putchar(first + 'a');
        }
    } else {
        putchar(second + 'a');
        for (int j = 0; j < cnt[first] - 1; j++) {
            putchar(first + 'a');
        }
        putchar(third + 'a');
        cnt[second]--;
        cnt[third]--;
        for (int i = first + 1; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                putchar(i + 'a');
            }
        }
    }
}

void DoubleFirst(int first)
{
    putchar(first + 'a');
    putchar(first + 'a');

    cnt[first] -= 2;

    for (int i = first + 1; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            putchar(i + 'a');
            if (cnt[first] > 0) {
                putchar(first + 'a');
                cnt[first]--;
            }
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int n = strlen(str);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cnt[str[i] - 'a']++;
        }

        int once = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1) {
                once = i;
                break;
            }
        }

        if (once != -1) {
            PrintZero(once);
        } else {
            int first = -1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) {
                    first = i;
                    break;
                }
            }

            assert(first != -1);

            if ((cnt[first] - 1) * 2 <= n) {
                DoubleFirst(first);
            } else {
                SingleFirst(first);
            }
        }
        putchar('\n');
    }

    return 0;
}