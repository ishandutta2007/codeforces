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

int a[2005]; int n;

bool check_good(int l, int r)
{
    vector<int> seq;
    for (int i = 1; i < l; i++) seq.push_back(a[i]);
    for (int i = r + 1; i <= n; i++) seq.push_back(a[i]);
    sort(seq.begin(), seq.end());
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] == seq[i-1]) return false;
    }
    return true;
}

bool check(int siz)
{
    for (int i = 1; i + siz - 1 <= n; i++) {
        if (check_good(i, i + siz - 1)) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    if (n == 1) {
        printf("0"); return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
        //printf("check %d ret %d\n", mid, (int)check(mid));
    }
    printf("%d", l);
    return 0;
}