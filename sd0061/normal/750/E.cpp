#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n , m;
char str[N];

struct opt {
    int w[5][5];
}t[N << 1];
opt operator + (const opt &A , const opt &B) {
    opt C;
    memset(C.w , 0x3f , sizeof(C.w));
    for (int i = 0 ; i < 5 ; ++ i) {
        for (int j = 0 ; j < 5 ; ++ j) {
            for (int k = 0 ; k < 5 ; ++ k) {
                C.w[i][k] = min(C.w[i][k] , A.w[i][j] + B.w[j][k]);
            }
        }
    }
    return C;
}

inline int id(int l , int r) {
    return l + r | l != r;
}

void build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        //cout << l << ' ' << r << ' ' << p << ' ' << str[l] << endl;;
        memset(t[p].w , 0x3f , sizeof(t[p].w));
        t[p].w[0][0] = 0;
        t[p].w[1][1] = 0;
        t[p].w[2][2] = 0;
        t[p].w[3][3] = 0;
        t[p].w[4][4] = 0;
        if (str[l] == '2') {
            //cout << 233 << endl;
            t[p].w[0][0] = 1;
            t[p].w[0][1] = 0;
        }
        if (str[l] == '0') {
            t[p].w[1][1] = 1;
            t[p].w[1][2] = 0;
        }
        if (str[l] == '1') {
            t[p].w[2][3] = 0;
            t[p].w[2][2] = 1;
        }
        if (str[l] == '6') {
            t[p].w[3][3] = 1;
            t[p].w[4][4] = 1;
        }
        if (str[l] == '7') {
            t[p].w[3][4] = 0;
            t[p].w[3][3] = 1;
        }
    } else {
        int mid = l + r >> 1;
        build(l , mid);
        build(mid + 1 , r);
        t[p]= t[id(l , mid)] + t[id(mid + 1 , r)];
    }
}

opt get(int l , int r , int top , int bot) {
    if (top <= l && r <= bot) {
        return t[id(l , r)];
    } else {
        int mid = l + r >> 1;
        if (bot <= mid) {
            return get(l , mid , top, bot);
        } else if (top > mid) {
            return get(mid + 1 , r , top , bot);
        } else {
            return get(l , mid , top, bot) + get(mid + 1 , r , top , bot);
        }
    }
}

int main() {
    scanf("%d%d" , &n , &m);
    scanf("%s" , str + 1);
    build(1 , n);
    //cout << (t[id(1 , 1)]).w[0][1] << endl;
    //cout << (t[id(1 , 1)] + t[id(2 , 2)]).w[0][2] << endl;
    for (int k = 0 ; k < m ; ++ k) {
        int l , r;
        scanf("%d%d" , &l , &r);
        int res = get(1 , n , l  , r).w[0][4];
        if (res > n) {
            puts("-1");
        } else {
            printf("%d\n" , res);
        }
    }

}