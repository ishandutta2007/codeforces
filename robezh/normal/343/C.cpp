#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5 + 500;

int n,m;
ll h[MAXN], p[MAXN];

ll cost(ll left, ll right, ll loc){
    if(left > loc) return right - loc;
    if(right < loc) return loc - left;
    return (right - left) + min(right - loc, loc - left);
}

bool check(ll t){
    int pos = 0, nextpos = -1;
    for(int i = 0; i < n; i++){
        while(nextpos+1 < m && cost(p[pos], p[nextpos+1], h[i]) <= t) nextpos++;
        if(nextpos == m-1) return true;
        pos = nextpos + 1;
    }
    return false;
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%I64d", &h[i]);
    for(int i = 0; i < m; i++) scanf("%I64d", &p[i]);

    ll l = -1, r = 2 * (ll)1e10 + 1, mid;

    //for(int i = 0; i < 10; i++) cout << check(i) << " ";
    while(l + 1 < r){
        mid = (l+r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;

}