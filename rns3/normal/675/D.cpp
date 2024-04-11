#include <bits/stdc++.h>
using namespace std;
const int M = 300001;
set<int> s;
int sto[M], a[M];
int pos[M];

int main() {
    //freopen("b.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sto[cnt ++] = a[i];
    sort(sto, sto + cnt);
    for(int i = 1; i <= n; i ++) a[i] = lower_bound(sto, sto + cnt, a[i]) - sto, pos[a[i]] = i;

    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        set<int> :: iterator it = s.lower_bound(x);
        int y = 0, id = -1;
        if(it != s.end() && y < pos[*it]) y = pos[*it], id = (*it);
        if(it != s.begin() && y < pos[*(--it)]) y = pos[*it], id = (*it);
        if(i > 1) printf("%d ", sto[id]);
        s.insert(x);
    }

}