#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int N = (int)1e5 + 500;
const ld EPS = 1e-8, INF = 1e20;

int n;
ld x[N], y[N];

bool check(ld r){
    ld mx = INF, mn = -INF;
    for(int i = 0; i < n; i++){
        //if(y[i] > 2*r) return false;
        if(fabs(y[i] - r) > r) return false;
        ld delta = sqrt(y[i]) * sqrt(2*r - y[i]);
        mn = max(mn, x[i] - delta);
        mx = min(mx, x[i] + delta);
        //cout << fixed << setprecision(10) << mn << " " << mx << endl;
    }
    return mn <= mx;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(y[i] > 0) pos++;
        else neg++, y[i] = -y[i];
    }
    if(pos && neg) return !printf("-1");


    //cout << EPS << endl;
    ld l = 0, r = 1e14, mid;
    //cout << r << endl;
    for(int i = 0; i < 150; i++){
        if(l < 1) mid = (l + r) / 2;
        else mid = sqrt(l) * sqrt(r);
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(10) << l << endl;
}