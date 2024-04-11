#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;


typedef long double ld;

const ld pi = atan2(0, -1);

struct pt{
    ld x, y;

    pt(){}

    pt(ld xx, ld yy){
        x = xx;
        y = yy;
    }

    ld operator * (const pt &a){
        return x * a.y - y * a.x;
    }

    ld operator % (const pt &a){
        return x * a.x + y * a.y;
    }

};

bool cmp(pt a, pt b){
    return a * b > 0;
}

ld ygol(pt a, pt b){
    ld h = atan2(a * b, a % b);
    h = h * 180.0 / pi;
    if (h < 0)
        h = h + 360.0;
    cerr << h << "\n";
    return h;
}

pt a[100033];
ld yg[100033], h;
int n;
ld my, ans = -0.7;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;

    if (n == 1){
        cout << "0";
        return 0;
    }

    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    for(int i = 0; i < n; i++){
        h = atan2(a[i].y, a[i].x);
        h = 180.0 * h / pi;
        if (h < 0)
            h = h + 360.0;
        yg[i] = h;
    }

    sort(yg, yg + n);
    yg[n] = yg[0] + 360;

    for(int i = 0; i < n; i++)
        ans = max(ans, yg[i + 1] - yg[i]);

    cout.precision(10);
    cout << fixed << 360.0 - ans;

    return 0;
}