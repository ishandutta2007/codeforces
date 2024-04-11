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

int T;
int n;
int p[1005]; int c[1005];

int main()
{
    scanf("%d", &T);
    for (int data = 1; data <= T; data++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", p + i, c + i);
        }
        bool good = true;
        if (p[1] < c[1]) good = false;
        for (int i = 2; i <= n; i++) {
            if (p[i] < c[i]) good = false;
            if (p[i] < p[i-1]) good = false;
            if (c[i] < c[i-1]) good = false;
            if (p[i] - p[i-1] < c[i] - c[i-1]) good = false;
        }
        printf("%s\n", good ? "YES" : "NO");
    }
    return 0;
}