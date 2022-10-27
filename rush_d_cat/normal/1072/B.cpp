//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 05:57:39 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5;

int n;
int a[MAXN], b[MAXN], t[MAXN];
bool flag = false;

void dfs(int x)
{
    if (flag) return;
    if (x == 0) {
        flag = true;
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%d ", t[i]);
        return;
    }
    for (int i = 0; i <= 3; i++) {
        if ((i | t[x + 1]) == a[x] && (i & t[x + 1]) == b[x]) {
            t[x] = i;
            dfs(x - 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i <= 3; i++) {
        t[n] = i;
        dfs(n - 1);
    }
    if (!flag) printf("NO\n");
	return 0;
}