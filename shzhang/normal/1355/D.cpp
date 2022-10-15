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

using namespace std;

#define ll long long

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    if (s >= n * 2) {
        printf("YES\n");
        for (int i = 1; i < n; i++) {
            printf("2 "); s -= 2;
        }
        printf("%d\n1\n", s);
    } else {
        printf("NO");
    }
    return 0;
}