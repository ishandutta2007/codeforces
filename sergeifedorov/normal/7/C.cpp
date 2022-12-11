#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const string task = "a";
const string inp = task + ".in";
const string outp = task + ".out";

int64 a,b,c,x,y;

int64 gcd (int64 a, int64 b, int64 &x, int64 &y)
{
    if (a == 0)
    {
        x = 0; y = 1;
        return b;
    }
    int64 x1, y1;
    int64 d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(outp.data(),"wt", stdout);

    cin >> a >> b >> c;
    if (a == 0){
        if (c % b == 0){
            cout << "0 " << -c/b << endl;
            return 0;
        }
        puts("-1");
        return 0;
    }
    if (b == 0){
        if (c % a == 0){
            cout << -c/a << " 0" << endl;
            return 0;
        }
        puts("-1");
        return 0;
    }

    int64 mn1,mn2;
    mn1 = mn2 = 1;
    if (a < 0){
        a *= -1;
        mn1 *= -1;
    }
    if (b < 0){
        b *= -1;
        mn2 *= -1;
    }

    int64 g = gcd(a,b,x,y);
    int64 r = (a - (c % a)) % a;
    
    if (r % g != 0){
        puts("-1");
        return 0;
    }
    int64 w = y * g / a;
    y -= w * (a / g);
    while (y >= a/g) y -= a/g;

    y *= r / g;
{   long double w = b;
    w = w * y + c;
    w = w / a;
    if (abs(w) > 5*1e18){
        puts("-1");
        return 0;
    }
    x = -w;
}   

    cout << mn1*x << " " << mn2*y << endl;
    return 0;
}