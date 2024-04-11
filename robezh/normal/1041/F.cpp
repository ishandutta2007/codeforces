#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,m,a,y;
int up[N], dn[N];

int main(){
    scanf("%d%d", &n, &y);
    for(int i = 0; i < n; i++) scanf("%d", &up[i]);
    scanf("%d%d", &m, &y);
    for(int i = 0; i < m; i++) scanf("%d", &dn[i]);

    int res = 0;
    int l = 1;
    while(l <= (int)1e9){
        l *= 2;
        map<int, int> cnt;
        for(int i = 0; i < n; i++) cnt[up[i] % l] ++;
        for(int j = 0; j < m; j++) cnt[(dn[j] + l/2) % l] ++;
        for(auto p : cnt) res = max(res, p.second);
    }
    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[up[i]] ++;
    for(int j = 0; j < m; j++) cnt[dn[j]] ++;
    for(auto p : cnt) res = max(res, p.second);
    cout << res << endl;

}