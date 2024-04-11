#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , id[N];
pair<int , int> a[N];
LL T;

bool cmp(pair<int , int> X , pair<int , int> Y) {
    return (LL)X.first * Y.second > (LL)X.second * Y.first;
}
bool cmpp(int X , int Y) {
    return a[X].first < a[Y].first;
}

double mx[N] , mn[N];

bool check(double c) {
    LL Tx = 0 , Tn = 0;
    for (int i = 0 , j = 0 , k = 0 ; i < n ; ++ i) {
        while (j < n && !cmp(a[i] , a[j])) {
            Tx += a[j ++].second;
        }
        while (k < n && cmp(a[k] , a[i])) {
            Tn += a[k ++].second;
        }
        mx[i] = a[i].first * (1.0 - c * (Tn + a[i].second) / T);
        mn[i] = a[i].first * (1.0 - c * Tx / T);
    }
    double MX = -1;
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        int x = id[i];
        while (j < n && a[id[j]].first < a[x].first) {
            MX = max(MX , mx[id[j ++]]);
        }
        if (MX > mn[x])
            return 0;
    }
    return 1;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].second);
        T += a[i].second;
        id[i] = i;
    }
    sort(a , a + n , cmp);
    sort(id , id + n , cmpp);
    double l = 0 , r = 1;
    for (int i = 0 ; i < 100 ; ++ i) {
        double m = (l + r) * 0.5;
        if (check(m))
            l = m;
        else
            r = m;
    }
    printf("%.12f\n" , (l + r) * 0.5);
    return 0;
}