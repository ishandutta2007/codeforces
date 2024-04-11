#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 150005;
const int Q = 1e9 + 7;

int n , a[N] , cnt;
bool f[N] , p[N];

int F(int x) {
    if (x >= n || x < 1)
        return 0;
    if (x & 1) {
        return (a[x] < a[x + 1]);
    } else {
        return (a[x] > a[x + 1]);
    }
}

int check(int i , int j) {
    int tmp = cnt;
    tmp -= F(i - 1);
    tmp -= F(i);
    if (i + 1 != j)
        tmp -= F(j - 1);
    tmp -= F(j);
    swap(a[i] , a[j]);

    tmp += F(i - 1);
    tmp += F(i);
    if (i + 1 != j)
        tmp += F(j - 1);
    tmp += F(j);



    swap(a[i] , a[j]);
    return tmp + 1 == n;
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i < n ; ++ i) {
        f[i] = F(i);
        if (!f[i]) {
            p[i] = p[i + 1] = 1;
        }
        cnt += f[i];
    }
    vector<int> V;
    for (int i = 1 ; i <= n ; ++ i) {
        if (p[i]) {
            V.push_back(i);
        }
    }
    if (V.size() > 30) {
        cout << 0 << endl;
    } else {
        int res = 0;
        for (int i = 0 ; i < V.size() ; ++ i) {
            for (int j = 1 ; j < V[i] ; ++ j) {
                if (!p[j])
                    res += check(j , V[i]);
            }
            for (int j = V[i] + 1 ; j <= n ; ++ j)
                res += check(V[i] , j);
        }
        cout << res << endl;
    }


    return 0;
}