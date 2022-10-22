#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
const int N = 505;
const int Q = 1e9 + 7;
typedef long long LL;
using namespace std;
char str[N];
int n , R[N];
int f[N][1 << 16];
int q[N] , r[N];
int A[1 << 16] , B[1 << 16];
inline int add(int& X , int Y) {
    X += Y;
    if (X >= Q)
        X -= Q;
}
void oror(int *F , int *a , int *b) {
    memcpy(A , a , sizeof(A));
    memcpy(B , b , sizeof(B));
    for (int j = 0 ; j < 16 ; ++ j)
        for (int i = 0 ; i < 1 << 16 ; ++ i)
            if (i >> j & 1) {
                add(A[i] , A[i ^ (1 << j)]);
                add(B[i]  ,B[i ^ (1 << j)]);
            }
    for (int i = 0 ; i < 1 << 16 ; ++ i)
        A[i] = (LL)A[i] * B[i] % Q;
    for (int j = 0 ; j < 16 ; ++ j)
        for (int i = 0 ; i < 1 << 16 ; ++ i)
            if (i >> j & 1) {
                add(A[i] , Q - A[i ^ (1 << j)]);
            }
    for (int i = 0 ; i < 1 << 16 ; ++ i)      
        add(F[i] , A[i]);
}
void andand(int *F , int *a , int *b) {
    int mask = (1 << 16) - 1;
    for (int i = 0 ; i < 1 << 16 ; ++ i) {
        A[i] = a[mask ^ i];
        B[i] = b[mask ^ i];
    }
    for (int j = 0 ; j < 16 ; ++ j)
        for (int i = 0 ; i < 1 << 16 ; ++ i)
            if (i >> j & 1) {
                add(A[i] , A[i ^ (1 << j)]);
                add(B[i]  ,B[i ^ (1 << j)]);
            }
    for (int i = 0 ; i < 1 << 16 ; ++ i)
        A[i] = (LL)A[i] * B[i] % Q;
    for (int j = 0 ; j < 16 ; ++ j)
        for (int i = 0 ; i < 1 << 16 ; ++ i)
            if (i >> j & 1) {
                add(A[i] , Q - A[i ^ (1 << j)]);
            }
    for (int i = 0 ; i < 1 << 16 ; ++ i)    
        add(F[i] , A[mask ^ i]);
}
void dfs(int l) {
    int cnt = 0;
    if (R[l] == l + 2) {
        for (int j = 0 ; j < 4 ; ++ j) {
            if (str[l + 1] == 'A' + j || str[l + 1] == '?') {
                for (int k = 0 ; k < 1 << 16 ; ++ k) {
                    int flag = 1;
                    for (int w = 0 ; w < 1 << 4 && flag ; ++ w)
                        if ((w >> j & 1) != ((k >> w & 1)))
                            flag = 0;
                    f[l][k] += flag;
                }
            }
            if (str[l + 1] == 'a' + j || str[l + 1] == '?') {
                for (int k = 0 ; k < 1 << 16 ; ++ k) {
                    int flag = 1;
                    for (int w = 0 ; w < 1 << 4 && flag ; ++ w)
                        if ((w >> j & 1) == ((k >> w & 1)))
                            flag = 0;
                    f[l][k] += flag;
                }
            }
        }
    } else {
        int x = l + 1 , y = R[l + 1] + 2;
        dfs(x);
        dfs(y);
        char c = str[y - 1];
        if (c == '|' || c == '?')
            oror(f[l] , f[x] , f[y]);
        if (c == '&' || c == '?')
            andand(f[l] , f[x] , f[y]);
    }
}

void work() {
    scanf("%s%d" , str + 1 , &n);
    int len = strlen(str + 1);
    str[0] = '(';
    str[len + 1] = ')';
    str[len + 2] = 0;
    memset(R , -1 , sizeof(R));
    stack<int> S;
    for (int i = 0 ; str[i] ; ++ i) {
        if (str[i] == '(')
            S.push(i);
        if (str[i] == ')') {
            R[S.top()] = i;
            S.pop();
        }
    }
    dfs(0);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < 4 ; ++ j) {
            int x;
            scanf("%d" , &x);
            q[i] |= x << j;
        }
        scanf("%d" , &r[i]);
    }
    int res = 0;
    for (int i = 0 ; i < 1 << 16 ; ++ i) {
        bool flag = 1;
        for (int j = 0 ; j < n && flag ; ++ j)
            if ((i >> q[j] & 1) != r[j])
                flag = 0;
        if (flag == 1) {
            res += f[0][i];
            res %= Q;
        }
    }
    printf("%d\n" , res);
}


int main() {
    work();
    return 0;
}