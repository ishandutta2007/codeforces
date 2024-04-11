#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool check(int a)
{
    char s[15];
    int freq[15];
    for (int i = 0; i < 10; i++) freq[i] = 0;
    sprintf(s, "%d", a);
    for (int i = 0; s[i]; i++) {
        freq[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 1) return false;
    }
    return true;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            printf("%d", i); return 0;
        }
    }
    printf("-1");
    return 0;
}