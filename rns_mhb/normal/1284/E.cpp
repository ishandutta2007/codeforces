#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pnt {
    int x, y;
    pnt(int x = 0, int y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
    pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
    pnt operator * (const int &b) const {return pnt(x * b, y * b);}
    pnt operator / (const int &b) const {return pnt(x / b, y / b);}
    int operator & (const pnt &b) const {return x * b.x + y * b.y;}
    ll operator * (const pnt &b) const {return 1ll * x * b.y - 1ll * b.x * y;}
    bool operator < (const pnt &b) const {
        if(y >= 0 && b.y < 0) return 0;
        if(y < 0 && b.y >= 0) return 1;
        return ((*this) * b) > 0;
    }
    bool operator != (const pnt &b) const {return x != b.x || y != b.y;}
    double dist() {return sqrt(x * x + y * y);}
    pnt rot() {return pnt(-y, x);}
    void in() {scanf("%d%d", &x, &y);}
};

#define N 2510

pnt p[N], a[N], b[N], c[N];

ll solve(int n) {
    int x = 0, y = 0;
    for(int i = 1; i <= n; i ++) if(a[i].y >= 0) b[++ x] = a[i];
    for(int i = 1; i <= n; i ++) if(a[i].y < 0) c[++ y] = a[i];
    sort(b+1, b+x+1);
    sort(c+1, c+y+1);
    ll ans = 1ll * n * (n-1) * (n-2) / 6;
    int j = 1;
    for(int i = 1; i <= x; i ++) {
        while(j <= y && (b[i]*c[j]) > 0) j ++;
        ans -= 1ll * (x-i+j-1) * (x-i+j-2) / 2;
    }
    j = 1;
    for(int i = 1; i <= y; i ++) {
        while(j <= x && (c[i]*b[j]) > 0) j ++;
        ans -= 1ll * (y-i+j-1) * (y-i+j-2) / 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) p[i].in();
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        int m = 0;
        for(int j = 1; j <= n; j ++) if(j != i) a[++ m] = p[j] - p[i];
        ans += solve(m);
    }
    ans = ans * (n-4) / 2;
    cout << ans << endl;
}