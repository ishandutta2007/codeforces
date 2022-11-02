#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> pii;

#define N 400100

int need[N];
int ned[N];

vector<int> v[N];
set<int> s[N];
int total, mon;
int n, m, flag;

bool check(int x){
    int mon = x;
    for(int j = x; j >= 1; j --){
        mon = min(j, mon);
        for(int i = 0; i < v[j].size(); i ++){
            int u = v[j][i];
            if(mon > ned[u]){
                mon -= ned[u];
                ned[u] = 0;
            }
            else{
                ned[u] -= mon;
                mon = 0;
            }
            if(!mon) break;
        }
        if(!mon) break;
    }
    int t = accumulate(ned + 1, ned + n + 1, 0);
    if(x - (total - t) >= 2 * t) return true;
    else return false;
}

int main(){
    int od, om;
    int maxn = 0;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++){
        scanf ("%d", &need[i]);
        total += need[i];
    }
    while (m --){
        scanf ("%d %d", &od, &om);
            v[od].push_back(om);
    }
    int l = total, r = total * 2;
    while (l < r) {
        for(int i = 1; i <= n; i ++){
            ned[i] = need[i];
        }
        int m = l + r >> 1;
        if (check(m)) r = m;
        else l = m + 1;
    }
    printf("%d", l);
}