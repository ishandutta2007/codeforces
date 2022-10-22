#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
const int M = N * 32;
int n , a[N];
int u[M][2] , cnt , v[M];

vector<int> dfs(int x , int num) {
    vector<int> V;
    for (int k = 0 ; k < 2 ; ++ k) {
        if (u[x][k]) {
            vector<int> R = dfs(u[x][k] , num << 1 | k);
            V.insert(V.end() , R.begin() , R.end());
        }
    }
    if (v[x]) {
        V.push_back(v[x]);
    } else if (num) {
        int x = 0;
        for (int p = 1 ; p < V.size() ; ++ p) {
            if (a[V[p]] > a[V[x]]) {
                x = p;
            }
        }
        a[V[x]] = num;
    }
    return V;
}

int main() {
    scanf("%d" , &n);
    cnt = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        int digit[32] , tot = 0 , x = a[i];
        while (x) {
            digit[tot ++] = x & 1;
            x >>= 1;
        }
        x = 1;
        for (int j = tot - 1 ; j >= 0 ; -- j) {
            int c = digit[j];
            if (!u[x][c]) {
                u[x][c] = ++ cnt;
            }
            x = u[x][c];
        }
        v[x] = i;
    }
    dfs(1 , 0);

    for (int i = 1 ; i <= n ; ++ i) {
        printf("%d%c" , a[i] , " \n"[i == n]);
    }

}