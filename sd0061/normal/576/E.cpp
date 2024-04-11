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
const int N = 500005;
const int M = 50;
int n , m , K , Q;
pair<int , int> e[N] , q[N];
int L[N] , R[N] , Hash[N];
bool res[N];
int f[M][N] , s[M][N] , v[M][N]; 

vector<int> t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define Left l , mid
#define Right mid + 1 , r
void insert(int l , int r , int top , int bot , int i) {
    if (top <= l && r <= bot) {
        t[id(l , r)].push_back(i);
        return;
    } int mid = l + r >> 1;
    if (top <= mid) insert(Left , top , bot , i);
    if (bot > mid) insert(Right , top , bot , i);
}
void getf(int k , int x , int& F , int &V) {
    V = 0;
    while (f[k][x] != x) {
        V ^= v[k][x];
        x = f[k][x];
    }
    F = x;
}
struct mess {
    int k , x , y;
};
void merge(int id , vector< mess >& V) {
    int k = q[id].second , i = q[id].first;
    int x = e[i].first , y = e[i].second;
    int X , Y , vx , vy;
    getf(k , x , X , vx);
    getf(k , y , Y , vy);
    if (X != Y) {
        if (s[k][X] > s[k][Y])
            swap(X , Y);
        f[k][X] = Y;
        s[k][Y] += s[k][X];
        v[k][X] = (vx ^ vy ^ 1);
        V.push_back((mess) {k , X , Y});
    }
}
void resume(mess& me) {
    int k = me.k , x = me.x , y = me.y;
    v[k][x] = 0;
    s[k][y] -= s[k][x];
    f[k][x] = x;
}

void divide(int l , int r) {
    int p = id(l , r);
    vector<mess> resu;
    for (auto &it : t[p])
        merge(it , resu);    
    if (l == r) {
        int k = q[l].second , i = q[l].first;
        int x = e[i].first , y = e[i].second;
        int X , Y , vx , vy;
        getf(k , x , X , vx);
        getf(k , y , Y , vy);
        if (X == Y && vx == vy) {
            res[l] = 0;
            if (~Hash[i] && l + 1 <= R[l])
                insert(0 , Q - 1 , l + 1 , R[l] , Hash[i]);
        } else {
            res[l] = 1;
            if (l + 1 <= R[l])
                insert(0 , Q - 1 , l + 1 , R[l] , l);
            Hash[i] = l;
        }        
    } else {
        int mid = l + r >> 1;
        divide(Left);
        divide(Right);
    }
    while (!resu.empty()) {
        resume(resu.back());
        resu.pop_back();           
    }
}

void work() {
    scanf("%d%d%d%d" , &n , &m , &K , &Q);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d%d" , &e[i].first,  &e[i].second);
        if (e[i].first > e[i].second)
            swap(e[i].first , e[i].second);
    }
    for (int i = 0 ; i < Q ; ++ i) {
        scanf("%d%d" , &q[i].first , &q[i].second);
        -- q[i].first , -- q[i].second;        
    }    
    for (int i = 0 ; i < m ; ++ i)
        Hash[i] = Q;
    for (int i = Q - 1 ; i >= 0 ; -- i) {
        R[i] = Hash[q[i].first] - 1;
        Hash[q[i].first] = i;
    }
    for (int i = 0 ; i < K ; ++ i)
        for (int j = 1 ; j <= n ; ++ j) {
            f[i][j] = j;
            s[i][j] = 1;
            v[i][j] = 0;
        }
    for (int i = 0 ; i < m ; ++ i)
        Hash[i] = -1;
    divide(0 , Q - 1);
    for (int i = 0 ; i < Q ; ++ i)
        puts(res[i] ? "YES" : "NO");
}

int main() {
    work();
    return 0;
}