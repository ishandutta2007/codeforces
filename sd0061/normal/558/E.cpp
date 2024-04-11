#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

pair<int , int> tt[26][N << 1];
pair<int , int> *t;
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
#define THIS p , l , mid , r

void pushdown(int p , int l , int mid , int r) {
    if (t[p].first) {
        int L = id(Left) , R = id(Right);
        t[L].first = t[R].first = t[p].first;
        t[L].second = (t[p].first - 1) * (mid - l + 1);
        t[R].second = (t[p].first - 1) * (r - mid);
        t[p].first = 0;
    }
}
void pushup(int p , int l , int mid , int r) {
    t[p].second = t[id(Left)].second + t[id(Right)].second;
}
void update(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].first = w;
        t[p].second = (w - 1) * (r - l + 1);
    } else {
        MID; pushdown(THIS);
        if (top <= mid)
            update(Left , top , bot , w);
        if (bot > mid)
            update(Right , top , bot , w);
        pushup(THIS);
    }
}
int get(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return t[p].second;
    } else {
        MID; pushdown(THIS); int res = 0;
        if (top <= mid)
            res += get(Left , top , bot);
        if (bot > mid)
            res += get(Right , top , bot);
        return res;
    }
}
int cnt[26];
int n , m;
char str[N];
void work() {
    scanf("%d%d%s" , &n , &m , str + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        t = tt[str[i] - 'a'];
        update(1 , n , i , i , 2);
    }
    while (m --) {
        int l , r , d;
        scanf("%d%d%d" , &l , &r , &d);
        memset(cnt , 0 , sizeof(cnt));
        for (int i = 0 ; i < 26 ; ++ i) {
            t = tt[i];
            cnt[i] = get(1 , n , l , r);
            update(1 , n , l , r , 1);
            //printf("%d%c" , cnt[i] , " \n"[i == 25]);
        }
        if (d) {
            for (int i = 0 ; i < 26 ; ++ i) {
                if (!cnt[i]) continue;
                t = tt[i];
                update(1 , n , l , l + cnt[i] - 1 , 2);
                l += cnt[i];
            }            
        } else {
            for (int i = 25 ; i >= 0 ; -- i) {
                if (!cnt[i]) continue;
                t = tt[i];
                update(1 , n , l , l + cnt[i] - 1 , 2);
                l += cnt[i];
            }
        }

    }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 0 ; j < 26 ; ++ j) {
            t = tt[j];
            if (get(1 , n , i , i)) {
                putchar('a' + j);
                break;
            }
        }
    puts("");
}

int main() {
    work();
    return 0;
}