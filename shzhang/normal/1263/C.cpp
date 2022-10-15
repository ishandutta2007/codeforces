#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int t;
    scanf("%d", &t);
    for (int data = 1; data <= t; data++) {
        int n;
        scanf("%d", &n);
        int l = 1, r;
        vector<int> ans;
        while (l <= n) {
            r = n/(n/l);
            ans.push_back(r);
            l = r + 1;
        }
        printf("%d\n", (int)ans.size()+1);
        printf("0 ");
        for (int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}