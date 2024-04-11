#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
#include <string>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define fab(i, a, b) for (int i = a; i <= int(b); i++)
#define fdown(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)

typedef long double ld;
typedef long long ll;

using namespace std;

const int maxn = 3E6+4;
const ld eps = 1e-9;

int n, t, m, len = 1;

struct pt{
    ll x, y;
    pt(){}

    pt(ll _x, ll _y){
        x = _x;
        y = _y;
    }

    ll operator % (const pt &a){
        return x * a.x + y * a.y;
    }

    ll operator * (const pt &a){
        return x * a.y - y * a.x;
    }

    pt operator * (const ld &a){
      pt q;
      q.x = x * a;
      q.y = y * a;
      return q;
    }

    pt operator + (const pt &a){
        pt b = a;
        b.x += x;
        b.y += y;
        return b;
    }
    pt operator - (const pt &a){
        return pt(x - a.x, y - a.y);
    }

    ld len(){
        return x * x + y * y;
    }

};

struct line{

    ld a, b, c;
    line (pt _a, pt _b){
        a = _a.y - _b.y;
        b = _b.x - _a.x;
        c = -_a.x * a - _a.y * b;
    }

    pt operator ^ (const line &x){
        pt ans;
        ans.y = (c * x.a - a * x.c) / (x.b * a - b * x.a);
        ans.x = (c * x.b - b * x.c) / (x.a * b - a * x.b);
        return ans;
    }
};

ld ygol(pt a, pt b){
    ld ans = atan2(a * b, a % b) / atan2(0, -1) * 180;
    if (ans + eps < 0) return ans + 360;
    return ans;
}

void rid1(pt &a){
    cin >> a.x >> a.y;
}

void rid2(pt &a, pt &b){
    rid1(a);
    rid1(b);
}

void rid4(pt &a, pt &b, pt &c, pt &d){
    rid2(a, b);
    rid2(c, d);
}

void wrt1(pt a){
  cout << fixed << a.x << " " << a.y << "\n";
}

void wrt2(pt a, pt b){
  wrt1(a);
  wrt1(b);
}

void wrt4(pt a, pt b, pt c, pt d){
    wrt2(a, b);
    wrt2(c, d);
}

pt q[10];
ld y[10];
int pos = -1;
pt a, b, c, d;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    pt a, b, c;

    rid2(a, b);
    rid1(c);

    ll h = ((a - b) * (c - b));

    if (h == 0) cout << "TOWARDS";
    if (h < 0) cout << "LEFT";
    if (h > 0) cout << "RIGHT";


    return 0;
}