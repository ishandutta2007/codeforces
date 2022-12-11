#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int64 mod = (int64)1e10;

struct myInt {
    int64 a;
    double b;

    myInt() {};

    myInt(int64 w) {
        a = w % mod;
        b = w;
    }

    myInt(int64 a, double b) : a(a), b(b) { };
};

int64 MUL(int64 a, int64 b) {
    if (1.0 * a * b < 1e18)
        return a * b % mod;
//  cerr << "here" << endl;
    int64 res = 0;
    forn(i, 40) {
        if (a & (1ll << i)) { 
            res += b;
            if (res >= mod) res -= mod;
        }
        b = b + b;
        if (b >= mod) b -= mod;
        if ((1ll << i) > a) break;
    }
    return res;
}

void write(myInt a) {
    if (a.b - a.a > mod - 1e-3) {
        printf("...");
        printf("%010I64d\n", a.a);
    } else {
        printf("%I64d\n", a.a);
    }
}

myInt operator + (myInt a, myInt b) {
    return myInt((a.a + b.a) % mod, a.b + b.b); 
}

myInt operator - (myInt a, myInt b) {
    return myInt((a.a - b.a + mod) % mod, a.b - b.b);   
}

myInt operator * (myInt a, myInt b) {
    return myInt((MUL(a.a, b.a)) % mod, a.b * b.b); 
}

myInt operator + (myInt a, int64 b) {
    return a + myInt(b);
}

myInt operator - (myInt a, int64 b) {
    return a - myInt(b);
}

myInt operator * (myInt a, int64 b) {
    return a * myInt(b);
}

myInt get(int64 x, int64 y) {
    if (x == y) 
        return myInt(x * (x - 1) + 1);
    if (x < y)
        return get(y, y) - (y - x);
    return get(x, x) + (x - y);
}


myInt sum(int64 a) {
    int64 b = a - 1;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    return myInt(a) * b;
}

myInt sumSq(int64 a) {
    int64 b = a + 1, c = 2 * a + 1;

    if (a % 2 == 0) a /= 2;
    else b /= 2;

    if (a % 3 == 0) a /= 3;
    else if (b % 3 == 0) b /= 3;
    else c /= 3;

    return (myInt(a) * b) * c;
}

myInt get(myInt st, int len, int cnt, int step) {
    myInt w(cnt);
    myInt res = (w * len) * st + w * sum(len);
    myInt now = sum(cnt) * step + sumSq(cnt - 1) - sum(cnt);
    return res + now * len;
}


myInt calcDown(int x1, int y1, int x2, int y2) {
    return get(get(x1, y1), x2 - x1 + 1, y2 - y1 + 1, 2 * y1 - 1);
}

myInt calcUp(int x1, int y1, int x2, int y2) {
    return get(get(x1, y2), y2 - y1 + 1, x2 - x1 + 1, 2 * x1 + 1);
}


myInt calcMid(int64 l, int64 r) {
    if (l == 1) {
        return sum(r * r + 1);
    }
    return calcMid(1, r) - calcMid(1, l-1) - calcDown(1, l, l - 1, r) - calcUp(l, 1, r, l-1);
}

myInt calc(int x1, int y1, int x2, int y2) {
    if (x1 > x2) return 0;
    if (y1 > y2) return 0;

    int a = max(x1, y1);
    int b = min(x2, y2);
    if (a == y1) {
        if (a >= x2)
            return calcDown(x1, y1, x2, y2);
        if (b < y2) 
            return calcMid(a, b) + calc(x1, y1, a - 1, b) + calc(x1, b + 1, x2, y2);
        else
            return calcMid(a, b) + calc(x1, y1, a - 1, b) + calc(b + 1, y1, x2, y2);
    }
    if (a == x1) {
        if (a >= y2)
            return calcUp(x1, y1, x2, y2);
        if (b < y2) 
            return calcMid(a, b) + calc(x1, y1, b, a - 1) + calc(x1, b + 1, x2, y2);
        else
            return calcMid(a, b) + calc(x1, y1, x2, a-1) + calc(b + 1, a, x2, y2);
    }
    assert(0);
    return myInt(0);
}

myInt stup(int x1, int y1, int x2, int y2) {
    myInt res = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j ++)
            res = res + get(i, j);
    return res;
}   


void check(int x1, int y1, int x2, int y2) {
    myInt r1 = calc(x1, y1, x2, y2);
    myInt r2 = stup(x1, y1, x2, y2);
    write(r1);
    write(r2);
}
       
int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  /*    for (int i = 1; i <= 5; i ++) {
        for (int j = 1; j <= 5; j ++)
            cout << get(i, j) << " ";
        cout << endl;
    }  */

/*  for (int i = 3; i <= 10; i ++)
        cerr << stup(3, 3, i, i) << " ";
    cerr << endl;

    for (int i = 3; i <= 10; i ++)
        cerr << calcMid(3, i) << " ";
    cerr << endl;

    return 0;*/

    /*check(1, 3, 3, 5);
    check(1, 3, 3, 6);
    check(1, 3, 3, 7);
    check(1, 3, 3, 50);

    check(3, 1, 3, 3);
    check(3, 1, 6, 3);
    check(3, 1, 7, 3);
    check(3, 1, 50, 3);

    check(2, 2, 5, 5); */

    //check(
    //return 0;

  //    write(MUL(9999999999ll, 9999999997ll));

    int n;
    cin >> n;
    forn(i, n) {
        int64 x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        write(calc(x1, y1, x2, y2));
    }   

    return 0;
}