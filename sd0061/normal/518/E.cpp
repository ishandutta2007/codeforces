#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , K;
int a[N];

inline LL cnt(int l , int r) {
    if (l >= 0)
        return ((LL)l + r) * ((LL)r - l + 1) / 2;
    if (r <= 0)
        return -((LL)l + r) * ((LL)r - l + 1) / 2;
    l = -l;
    return (LL)l * (l + 1) / 2 + (LL)r * (r + 1) / 2;
}
inline LL sum(int l , int r , int K , int x) {
    LL res = 1LL << 60;
    if (K > (LL)r - l + 1)
        return res;
    if (!K) return 0;
    if (l <= -K / 2 && r >= K - K / 2 - 1) {
        int y = -K / 2 , z = 0;
        while (z < K) {
            a[x] = y ++;
            z ++ , x += ::K;
        }
        return 0;
    }
    if (l <= -K + K / 2 + 1 && r >= K / 2) {
        int y = -K + K / 2 + 1 , z = 0;
        while (z < K) {
            a[x] = y ++;
            z ++ , x += ::K;
        }
        return 0;
    }
    int y , z = 0;
    if (cnt(l , l + K - 1) < cnt(r - K + 1 , r))
        y = l;
    else
        y = r - K + 1;
    while (z < K) {
        a[x] = y ++;
        z ++ , x += ::K;
    }
    return 0;
}

void work() {
    int i , j , k , x , y;
    char str[20];
    scanf("%d%d",&n,&K);

    for (i = 0; i < n ; ++ i) {
        scanf("%s" , str);
        if (*str == '?') {
            a[i] = Q;
        } else {
            sscanf(str , "%d" , &a[i]);
        }
    }
    LL res = 0;
    for (i = 0 ; i < K ; ++ i) {
        vector< int > b , d;
        vector< int > c;
        j = i;
        while (1) {
            x = 0;
            d.push_back(j);
            while (j < n && a[j] == Q)
                j += K , ++ x;
            b.push_back(x);
            if (j < n && a[j] != Q)
                c.push_back(a[j]) , j += K;
            else if (j >= n)
                break;
        }
        if (c.empty()) {
            res += sum(-1 << 30 , 1 << 30 , b[0] , d[0]);
            continue;
        }
        res += sum(-1 << 30 , c[0] - 1 , b[0] , d[0]);
        for (j = 1 ; j < c.size() ; ++ j) {
            LL tmp = sum(c[j - 1] + 1 , c[j] - 1 , b[j] , d[j]);
            if (tmp == 1LL << 60) {
                puts("Incorrect sequence");
                return;
            }
            res += tmp;
        }
        res += sum(c[j - 1] + 1 , 1 << 30 , b[j] , d[j]);
    }
    for (i = 0 ; i < n ; ++ i)
        printf("%d " , a[i]);
}

int main() {
    work();
    return 0;
}