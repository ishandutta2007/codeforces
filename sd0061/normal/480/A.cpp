#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
pair<int , int> a[N];

void work() {
    int i;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second);
    sort(a , a + n);
    int res = 0;
    for (i = 0 ; i < n ; ++ i) {
        if (a[i].second >= res)
            res = a[i].second;
        else
            res = a[i].first;
    }
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}