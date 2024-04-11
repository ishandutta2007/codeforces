#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N];
int cnt[N] , odd , neg , sum;
int f[N];
LL res;
bool check(int L , int R) {
    #define in(x) (L <= (x) && (x) <= R)
    for (int i = 1 ; i <= n ; ++ i)
        if (!in(i) && !in(n - i + 1) && a[i] != a[n - i + 1])
            return 0;
    for (int i = 1 ; i <= n ; ++ i)
        cnt[i] = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (in(i)) {
            ++ cnt[a[i]];
        } else if (in(n - i + 1))
            -- cnt[a[i]];
    }
    int sum = 0;
    for (int i = 1 ; i <= n ; ++ i)
        if (cnt[i] < 0)
            return 0;
        else
            sum += (cnt[i] & 1);
    return sum <= (n & 1);
}

bool ok(int l , int r) {
    if (r <= n / 2)
        return (f[r] - f[l - 1] == sum);
    if (l >= (n + 1) / 2 + 1) {
        l = n - l + 1;
        r = n - r + 1;
        return (f[l] - f[r - 1] == sum);
    }
    r = n - r + 1;
    return (f[n / 2] - f[min(l , r) - 1] == sum);
}

void work() {
    int i , j , k;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (i = 1 ; i <= n / 2 ; ++ i)
        f[i] = f[i - 1] + (a[i] != a[n - i + 1]);
    sum = f[n / 2];
    i = 1 , j = 0 ; //[i , j)
    while (i <= n) {
        while (j <= n && (j < i || ( !ok(i , j) || neg || odd > (n & 1)))) {
            ++ j;
            k = n - j + 1;
            if (cnt[a[j]] < 0) -- neg;
            if (cnt[a[j]] & 1) -- odd;
            if (a[j] != a[k]) {
                if (cnt[a[k]] < 0) -- neg;
                if (cnt[a[k]] & 1) -- odd;
            }
            ++ cnt[a[j]];
            if (i <= k && k <= j) {
                if (j != k)
                    ++ cnt[a[j]];
            } else
                -- cnt[a[k]];
            if (cnt[a[j]] < 0) ++ neg;
            if (cnt[a[j]] & 1) ++ odd;
            if (a[j] != a[k]) {
                if (cnt[a[k]] < 0) ++ neg;
                if (cnt[a[k]] & 1) ++ odd;
            }
            //add(j);
        }
        //del(i)
        k = n - i + 1;
        if (cnt[a[i]] < 0) -- neg;
        if (cnt[a[i]] & 1) -- odd;
        if (a[i] != a[k]) {
            if (cnt[a[k]] < 0) -- neg;
            if (cnt[a[k]] & 1) -- odd;
        }
        -- cnt[a[i]];
        if (i < k && k <= j) {
            if (i != k)
                -- cnt[a[i]];
        } else {
            ++ cnt[a[k]];
        }
        if (cnt[a[i]] < 0) ++ neg;
        if (cnt[a[i]] & 1) ++ odd;
        if (a[i] != a[k]) {
            if (cnt[a[k]] < 0) ++ neg;
            if (cnt[a[k]] & 1) ++ odd;
        }
        //printf("%d #: %d\n" , i , j);
        res += n - j + 1;
        ++ i;
    }


//    for (i = 1 ; i <= n ; ++ i) {
//        for (j = i ; j <= n ; ++ j) {
//            if (check(i , j))
//                break;
//        }
//        printf("%d : %d\n" , i , j);
//        res += n - j + 1;
//    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}