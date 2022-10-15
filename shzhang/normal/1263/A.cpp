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
    for (int i = 1; i <= t; i++) {
        vector<int> cnt;
        for (int j = 1; j <= 3; j++) {
            int a;
            scanf("%d", &a); cnt.push_back(a);
        }
        //for (int j = 0; j < 3; j++) printf("%d ", cnt[j]);
        sort(cnt.begin(), cnt.end());
        //for (int j = 0; j < 3; j++) printf("%d ", cnt[j]);
        if (cnt[0] + cnt[1] > cnt[2]) {
            printf("%d\n", (cnt[0] + cnt[1] + cnt[2]) / 2);
        } else {
            printf("%d\n", cnt[0] + cnt[1]);
        }
    }
    return 0;
}