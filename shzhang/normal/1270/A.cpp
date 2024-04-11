#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

void work(void)
{
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    priority_queue<int> a, b;
    for (int i = 1; i <= k1; i++) {
        int x;
        scanf("%d", &x);
        a.push(x);
    }
    for (int i = 1; i <= k2; i++) {
        int x;
        scanf("%d", &x);
        b.push(x);
    }
    while (!a.empty() && !b.empty()) {
        if (a.top() > b.top()) {
            a.push(b.top());
            b.pop();
        } else {
            b.push(a.top());
            a.pop();
        }
    }
    if (!a.empty()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}