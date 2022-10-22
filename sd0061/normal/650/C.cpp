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
const int N = 1000005;

int n , m , a[N] , num;
int f[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
inline void merge(int x , int y) {
    f[getf(x)] = getf(y);
}
pair<int , int> c[N];
vector<int> e[N];
int deg[N] , F[N];
inline void addedge(int x , int y) {
    x = getf(x) , y = getf(y);
    e[x].push_back(y); // x < y;
    ++ deg[y];
}

int main() {
    scanf("%d%d" , &n , &m);
    num = n * m;
    for (int i = 0 ; i < num ; ++ i) {
        scanf("%d" , &a[i]);
        f[i] = i;
    }

    for (int i = 0 ; i < n ; ++ i) {
        int id = i * m;
        for (int j = 0 ; j < m ; ++ j) {
            c[j] = make_pair(a[id] , id);
            ++ id;
        }
        sort(c , c + m);
        for (int j = 0 ; j < m ; ) {
            int k = j;
            while (k < m && c[j].first == c[k].first) {
                merge(c[j].second , c[k].second);
                ++ k;
            }
            j = k;
        }        
    }
    for (int i = 0 ; i < m ; ++ i) {
        int id = i;
        for (int j = 0 ; j < n ; ++ j) {
            c[j] = make_pair(a[id] , id);
            id += m;
        }
        sort(c , c + n);
        for (int j = 0 ; j < n ; ) {
            int k = j;
            while (k < n && c[j].first == c[k].first) {
                merge(c[j].second , c[k].second);
                ++ k;
            }
            j = k;
        }  
    }
    for (int i = 0 ; i < n ; ++ i) {
        int id = i * m;
        for (int j = 0 ; j < m ; ++ j) {
            c[j] = make_pair(a[id] , id);
            ++ id;
        }
        sort(c , c + m);
        for (int j = 0 ; j < m ; ) {
            int k = j;
            while (k < m && c[j].first == c[k].first) {
                ++ k;
            }
            if (k < m) {
                addedge(c[j].second , c[k].second);
            }
            j = k;            
        }
    }
    for (int i = 0 ; i < m ; ++ i) {
        int id = i;
        for (int j = 0 ; j < n ; ++ j) {
            c[j] = make_pair(a[id] , id);
            id += m;
        }
        sort(c , c + n);
        for (int j = 0 ; j < n ; ) {
            int k = j;
            while (k < n && c[j].first == c[k].first) {
                ++ k;
            }            
            if (k < n) {
                addedge(c[j].second , c[k].second);
            }
            j = k;
        }  
    }
    queue<int> Q;
    for (int i = 0 ; i < num ; ++ i) {
        if (getf(i) == i && !deg[i])
            Q.push(i);
    }
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        ++ F[x];
        for (auto &y : e[x]) {
            F[y] = max(F[y] , F[x]);
            if (!-- deg[y]) {
                Q.push(y);
            }
        }
    }
    num = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            printf("%d%c" , F[getf(num)] , " \n"[j + 1 == m]);
            ++ num;
        }
    }
}