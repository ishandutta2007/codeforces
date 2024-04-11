#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long bll;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

struct pnt {
    ll x, y;
    pnt operator - (const pnt &a) const {return pnt{x - a.x, y - a.y};}
    ll operator * (const pnt &a) const {return (ll)x * a.y - (ll)y * a.x;}
    double dist() {return sqrt((ll)x * x + (ll)y * y);}
    void in() {scanf("%I64d%I64d", &x, &y);}
} p[1010], a, b, c;

int main() {
    int n, i;
    double ans = inf;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) p[i].in();
    for(i = 0; i < n; i ++) {
        a = p[i];
        b = p[(i + 1) % n];
        c = p[(i + 2) % n];
        chkmin(ans, abs((b - a) * (b - c)) / (c - a).dist() / 2);
    }
    printf("%.8lf\n", ans);
}