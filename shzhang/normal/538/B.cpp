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

int n;

int find(int a)
{
    int curpwr = 1;
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (a % 10) ans += curpwr;
        a /= 10;
        curpwr *= 10;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    vector<int> ans;
    while (n) {
        int a = find(n);
        ans.push_back(a); n -= a;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}