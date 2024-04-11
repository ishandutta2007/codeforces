#include <bits/stdc++.h>
using namespace std;

const int N = 140000;

typedef pair<int, int> P;

int n;
P lf[N], rt[N], up[N], dn[N];
P ans;

bool check(int i){
    int l, r, u, d;
    l = (lf[n-1].second == i ? lf[n-2].first : lf[n-1].first);
    r = (rt[0].second == i ? rt[1].first : rt[0].first);
    u = (up[0].second == i ? up[1].first : up[0].first);
    d = (dn[n-1].second == i ? dn[n-2].first : dn[n-1].first);
    if(l <= r && d <= u){
        ans.first = l, ans.second = d;
        return true;
    }
    else return false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &lf[i].first, &dn[i].first, &rt[i].first, &up[i].first);
        lf[i].second = dn[i].second = rt[i].second = up[i].second = i;
    }
    sort(lf, lf+n); sort(rt, rt+n); sort(up, up+n); sort(dn, dn+n);
    for(int i = 0; i < n; i++){
        if(check(i)){
            return !printf("%d %d\n", ans.first, ans.second);
        }
    }
}