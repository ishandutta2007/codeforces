#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5 + 500;

int n, l, wmax,a,b, nl = 0, nr = 0;
int lft[MAXN], rgt[MAXN];

bool check(int i, int t){
    ll time = (lft[t] - rgt[i] + l);
    ll inter = abs(lft[t] + rgt[i] + l);
    return time * wmax > inter;
}

ll get(int i){
    int l = -1, r = nl, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(i, mid)) r = mid;
        else l = mid;
    }
    return nl - r;
}


int main(){
    scanf("%d%d%d", &n, &l, &wmax);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        if(b == 1) rgt[nr++] = a;
        else lft[nl++] = a;
    }
    sort(rgt, rgt+nr);
    sort(lft, lft+nl);

    ll ans = 0;
    for(int i = 0; i < nr; i++){
        ans += get(i);
    }
    cout << ans << endl;

}