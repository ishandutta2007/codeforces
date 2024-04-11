#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 5005;
int n , m;
int c[M][M];
int type[N] , X[N] , Y[N] , len[N] , dir[N] , res[N];

int w[N] , nw , v[N] , nv;
bool cmp1(const int& A , const int& B) {
    return X[A] + Y[A] + len[A] > X[B] + Y[B] + len[B];
}
bool cmp2(const int& A , const int& B) {
    return X[A] - Y[A] + len[A] > X[B] - Y[B] + len[B];
}
bool cmp3(const int& A , const int& B) {
    return X[A] + Y[A] - len[A] < X[B] + Y[B] - len[B];
}
bool cmp4(const int& A , const int& B) {
    return X[A] - Y[A] - len[A] < X[B] - Y[B] - len[B];
}


void divide(int l , int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    divide(l , mid);

    nv = 0;
    for (int i = mid + 1 ; i <= r ; ++ i)
        if (type[i] == 2)
            v[nv ++] = i;
    
    nw = 0;
    for (int i = l ; i <= mid ; ++ i)
        if (type[i] == 1 && dir[i] == 1)
            w[nw ++] = i;
    sort(w , w + nw , cmp1);
    sort(v , v + nv , cmp1);
    for (int i = 0 , j = 0 ; i < nv ; ++ i) {
        int x = v[i];
        while (j < nw) {
            int y = w[j];
            if (!(X[x] + Y[x] <= X[y] + Y[y] + len[y]))
                break;
            for (int k = X[y] ; k <= n ; k += k & -k)
                for (int l = Y[y] ; l <= n ; l += l & -l)
                    ++ c[k][l];
            ++ j;
        }
        int &ret = res[x];
        for (int k = X[x] ; k > 0 ; k -= k & -k)
            for (int l = Y[x] ; l > 0 ; l -= l & -l)
                ret += c[k][l];
    }
    for (int j = 0 ; j < nw ; ++ j) {
        int y = w[j];
        for (int k = X[y] ; k <= n ; k += k & -k)
            for (int l = Y[y] ; l <= n ; l += l & -l)
                c[k][l] = 0;
    }
    
    nw = 0;
    for (int i = l ; i <= mid ; ++ i)
        if (type[i] == 1 && dir[i] == 3)
            w[nw ++] = i;
    sort(w , w + nw , cmp3);
    sort(v , v + nv , cmp3);
    for (int i = 0 , j = 0 ; i < nv ; ++ i) {
        int x = v[i];
        while (j < nw) {
            int y = w[j];
            if (!(X[x] + Y[x] >= X[y] + Y[y] - len[y]))
                break;
            for (int k = X[y] ; k > 0 ; k -= k & -k)
                for (int l = Y[y] ; l > 0 ; l -= l & -l)
                    ++ c[k][l];
            ++ j;
        }
        int &ret = res[x];
        for (int k = X[x] ; k <= n ; k += k & -k)
            for (int l = Y[x] ; l <= n ; l += l & -l)                
                ret += c[k][l];
    }
    for (int j = 0 ; j < nw ; ++ j) {
        int y = w[j];
        for (int k = X[y] ; k > 0 ; k -= k & -k)
            for (int l = Y[y] ; l > 0 ; l -= l & -l)
                c[k][l] = 0;
                }

    nw = 0;
    for (int i = l ; i <= mid ; ++ i)
        if (type[i] == 1 && dir[i] == 2)
            w[nw ++] = i;
    sort(w , w + nw , cmp2);
    sort(v , v + nv , cmp2);
    for (int i = 0 , j = 0 ; i < nv ; ++ i) {
        int x = v[i];
        while (j < nw) {
            int y = w[j];
            if (!(X[x] - Y[x] <= X[y] - Y[y] + len[y]))
                break;
            for (int k = X[y] ; k <= n ; k += k & -k)
                for (int l = Y[y] ; l > 0 ; l -= l & -l)
                    ++ c[k][l];
            ++ j;
        }
        int &ret = res[x];
        for (int k = X[x] ; k > 0 ; k -= k & -k)
            for (int l = Y[x] ; l <= n ; l += l & -l)
                ret += c[k][l];
    }
    for (int j = 0 ; j < nw ; ++ j) {
        int y = w[j];
        for (int k = X[y] ; k <= n ; k += k & -k)
            for (int l = Y[y] ; l > 0 ; l -= l & -l)
                c[k][l] = 0;
    }

    nw = 0;
    for (int i = l ; i <= mid ; ++ i)
        if (type[i] == 1 && dir[i] == 4)
            w[nw ++] = i;
    sort(w , w + nw , cmp4);
    sort(v , v + nv , cmp4);
    for (int i = 0 , j = 0 ; i < nv ; ++ i) {
        int x = v[i];
        while (j < nw) {
            int y = w[j];
            if (!(X[x] - Y[x] >= X[y] - Y[y] - len[y]))
                break;
            for (int k = X[y] ; k > 0 ; k -= k & -k)
                for (int l = Y[y] ; l <= n ; l += l & -l)
                    ++ c[k][l];
            ++ j;
        }
        int &ret = res[x];
        for (int k = X[x] ; k <= n ; k += k & -k)
            for (int l = Y[x] ; l > 0 ; l -= l & -l)
                ret += c[k][l];
    }
    for (int j = 0 ; j < nw ; ++ j) {
        int y = w[j];
        for (int k = X[y] ; k > 0 ; k -= k & -k)
            for (int l = Y[y] ; l <= n ; l += l & -l)
                c[k][l] = 0;
    }

    divide(mid + 1 , r);
}

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d" , &type[i]);
        if (type[i] == 1) {
            scanf("%d%d%d%d" , &dir[i] , &X[i] , &Y[i] , &len[i]);
            if (dir[i] == 3 || dir[i] == 4)
                dir[i] = 7 - dir[i];
        } else {
            scanf("%d%d" , &X[i] , &Y[i]);
        }
    }
    divide(0 , m - 1);
    for (int i = 0 ; i < m ; ++ i)
        if (type[i] == 2)
            printf("%d\n" , res[i]);
}

int main() {
    work();
    return 0;
}