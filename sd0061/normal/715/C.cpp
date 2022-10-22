#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , w , next;
} e[N << 1];
int power[N] , inv[N] , s[N];
bool f[N];
LL res;

pair<int , int> Find(int x , int fa , int cnt) {
    s[x] = 1; int mq = 0;
    pair<int , int> res = make_pair(1 << 30 , -1);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa) {
            res = min(res , Find(e[i].x , x , cnt));
            mq = max(s[e[i].x] , mq);
            s[x] += s[e[i].x];
        }
    mq = max(mq , cnt - s[x]);
    return min(res , make_pair(mq , x));
}
int a[N] , b[N];
LL count(vector< pair<int , int> > &W) {
    int k = W.size();
    for (int i = 0 ; i < k ; ++ i) {
        a[i] = W[i].first;
        b[i] = W[i].second;
    }
    sort(a , a + k);
    sort(b , b + k);
    LL cnt = 0;

    for (int i = 0 , l = 0 , r = 0 ; i < k ; ++ i) {
        while (l < k && b[l] < a[i]) ++ l;
        while (r < k && b[r] <= a[i]) ++ r;
        cnt += r - l;
    }

    return cnt;
}

void Getdis(int x , int fa , int d , int ha , int hb , vector< pair<int , int> >& W) {
    //printf("%d : %d %d %d\n" , x , d , ha , hb);
    //int qa = (LL)(m - ha) * inv[d] % m;
    int qb = (LL)(m - hb) * inv[d] % m;
    W.push_back({ha , qb});
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa) {
            Getdis(y , x , d + 1 ,  (ha + (LL)e[i].w * power[d]) % m , ((LL)hb * 10 + e[i].w) % m , W);
        }
    }
}
void divide(int x , int cnt) {
    x = Find(x , 0 , cnt).second;
    f[x] = 1;

    vector< pair<int , int> > V;
    V.push_back({0 , 0}); res -= 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            vector< pair<int , int> > W;
            Getdis(y , x , 1 , e[i].w % m , e[i].w % m , W);
            res -= count(W);
            V.insert(V.end() , W.begin() , W.end());
            s[y] = W.size();
        }
    }
    res += count(V);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y])
            divide(y , s[y]);
    }
}
void exgcd(int a, int b, int &g, int &x, int &y) {
    if (!b) x = 1, y = 0, g = a;
    else {
        exgcd(b, a % b, g, y, x);
        y -= x * (a / b);
    }
}
int main() {
    scanf("%d%d" , &n , &m);
    int G , X , Y;
    exgcd(10 , m , G , X , Y);
    X = (X % m + m) % m;

    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i < n ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        ++ x, ++ y;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    power[0] = inv[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        power[i] = (LL)power[i - 1] * 10 % m;
        inv[i] = (LL)inv[i - 1] * X % m;
    }
    divide(1 , n);
    cout << res << endl;
}