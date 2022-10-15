#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

char s[200];
const char* goal = "CODEFORCES";

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    if (n <= 10) {
        printf("NO"); return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (n - (j - i) != 10) continue;
            bool good = true;
            int cur = 0;
            while (cur < i) {
                if (s[cur] != goal[cur]) good = false;
                cur++;
            }
            int index = cur;
            cur = j;
            while (cur < n) {
                if (s[cur] != goal[index]) good = false;
                cur++; index++;
            }
            if (good) {
                printf("YES"); return 0;
            }
        }
    }
    printf("NO");
    return 0;
}