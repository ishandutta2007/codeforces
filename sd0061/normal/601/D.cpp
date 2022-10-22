#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
const int N = 300005;
const int Q1 = 1002324329;
const int Q2 = 998244353;
const int MAGIC = 31;
int n , c[N];
char s[N];
vector<int> E[N];
int w[N] , a1[N] , b1[N] , a2[N] , b2[N];

int inverse(int x , int Q) {
    return x == 1 ? 1 : (LL)(Q - Q / x) * inverse(Q % x , Q) % Q;
}
set< pair<int , int> > Hash[N];
void merge(int x , int y) {
    int i1 = inverse(a1[x] , Q1);
    int i2 = inverse(a2[x] , Q2);    
    while (!Hash[y].empty()) {
        int u = Hash[y].begin() -> first;
        int v = Hash[y].begin() -> second;        
        Hash[y].erase(Hash[y].begin());
        
        u = ((LL)u * a1[y] + b1[y] + Q1 - b1[x]) % Q1;
        u = (LL)u * i1 % Q1;
        v = ((LL)v * a2[y] + b2[y] + Q2 - b2[x]) % Q2;
        v = (LL)v * i2 % Q2;
        Hash[x].insert({u , v});
    }    
}

void dfs(int x , int fa) {
    Hash[x].insert({0 , 0});
    a1[x] = 1 , b1[x] = 0;
    a2[x] = 1 , b2[x] = 0;    
    for (auto &y : E[x]) {
        if (y != fa) {
            dfs(y , x);
            if (Hash[x].size() < Hash[y].size()) {
                swap(Hash[x] , Hash[y]);
                swap(a1[x] , a1[y]);
                swap(b1[x] , b1[y]);
                swap(a2[x] , a2[y]);
                swap(b2[x] , b2[y]);                
            }
            merge(x , y);
        }
    }
    w[x] = Hash[x].size();
    a1[x] = (LL)a1[x] * MAGIC % Q1;
    b1[x] = ((LL)b1[x] * MAGIC + (s[x] - 'a' + 1)) % Q1;
    a2[x] = (LL)a2[x] * MAGIC % Q2;
    b2[x] = ((LL)b2[x] * MAGIC + (s[x] - 'a' + 1)) % Q2;    
}

void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , &c[i]);
    scanf("%s" , s + 1);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs(1 , 0);
    int res = -1 << 30 , cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        res = max(res , w[i] + c[i]);
        //  printf("%d : %d %d\n" , i , w[i] , c[i]);
    }
    for (int i = 1 ; i <= n ; ++ i)
        cnt += (w[i] + c[i] == res);
    cout << res << endl << cnt << endl;
}

int main() {
    work();
    return 0;
}