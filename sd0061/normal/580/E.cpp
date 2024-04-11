#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q1 = 1e9 + 7;
const int Q2 = 1e9 + 9;
const int MAGIC = 10;
int power1[N] , power2[N];
int inverse(int x , int Q) {
    return x == 1 ? x : (LL)(Q - Q / x) * inverse(Q % x , Q) % Q;
}
const int inv1 = inverse(MAGIC - 1 , Q1);
const int inv2 = inverse(MAGIC - 1 , Q2);

struct stree {
    int h1 , h2 , f;
    void set(int w , int len) {
        f = w;
        h1 = (LL)w * (power1[len] - 1) % Q1 * inv1 % Q1;
        h2 = (LL)w * (power2[len] - 1) % Q2 * inv2 % Q2;
    }
}t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define THIS p , l , mid , r
#define Left l , mid
#define Right mid + 1 , r

void pushdown(int p , int l , int mid , int r) {
    if (~t[p].f) {
        int L = id(Left) , R = id(Right);
        t[L].set(t[p].f , mid - l + 1);
        t[R].set(t[p].f , r - mid);
        t[p].f = -1;
    }
}
void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].h1 = ((LL)t[L].h1 * power1[r - mid] + t[R].h1) % Q1;
    t[p].h2 = ((LL)t[L].h2 * power2[r - mid] + t[R].h2) % Q2;
}
void set(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].set(w , r - l + 1);
        return;
    } MID; pushdown(THIS);
    if (top <= mid) set(Left , top , bot , w);
    if (bot > mid) set(Right , top , bot , w);
    pushup(THIS);
}
pair<int , int> get(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return make_pair(t[p].h1 , t[p].h2);
    } MID; pushdown(THIS);
    if (bot <= mid)
        return get(Left , top , bot);
    else if (top > mid)
        return get(Right , top , bot);
    else {
        pair<int , int> L = get(Left , top , bot);
        pair<int , int> R = get(Right , top , bot);
        pair<int , int> res;
        res.first = ((LL)L.first * power1[min(bot , r) - mid] + R.first) % Q1;
        res.second = ((LL)L.second * power2[min(bot , r) - mid] + R.second) % Q2;
        return res;
    }
}

int n , m , K;
char str[N];

int main() {
    scanf("%d%d%d%s" , &n , &m , &K , str + 1);
    power1[0] = 1;
    power2[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        power1[i] = (LL)power1[i - 1] * MAGIC % Q1;
        power2[i] = (LL)power2[i - 1] * MAGIC % Q2;
    }
    for (int i = 1 ; i <= n ; ++ i)
        set(1 , n , i , i , str[i] - '0');
    for (int i = 0 ; i < m + K ; ++ i) {
        int j , l , r , x;
        scanf("%d%d%d%d" , &j , &l ,&r , &x);
        if (j == 1)
            set(1 , n , l , r , x);
        else {
            if (x == r - l + 1)
                puts("YES");
            else {
                x = r - l + 1 - x;
                pair<int , int> L = get(1 , n , l , l + x - 1);
                pair<int , int> R = get(1 , n , r - x + 1 , r);
                //cout << L.first << ' ' << R.first << endl;
                //cout << L.second << ' ' << R.second << endl;
                puts(L == R ? "YES" : "NO");
            }
        }
    }
    return 0;
}