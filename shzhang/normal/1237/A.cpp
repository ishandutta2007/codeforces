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

int a[15000]; int n;
int ans[15000];

int absolute(int X)
{
    return  X< 0 ? -X : X;
}

int main()
{
    scanf("%d", &n);
    vector<int> seq;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (absolute(a[i]) % 2 != 0) seq.push_back(i);
        else ans[i] = a[i] / 2;
    }
    for (int i = 0; i < seq.size() / 2; i++) {
        int s = seq[i];
        if (a[s] < 0) {
            ans[s] = -(absolute(a[s]) / 2) - 1;
        } else {
            ans[s] = a[s] / 2;
        }
    }
    for (int i = seq.size() / 2; i < seq.size(); i++) {
        int s = seq[i];
        if (a[s] < 0) {
            ans[s] = -(absolute(a[s]) / 2);
        } else {
            ans[s] = a[s] / 2 + 1;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}