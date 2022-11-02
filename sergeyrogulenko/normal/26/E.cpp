#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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

int n, w;
int a[100];

void write (int v)
{
    printf ("%d ", v + 1);
}

int main ()
{
//  freopen ("input.txt", "r", stdin);
//  freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &w);
    forn (i, n)
        scanf ("%d", &a[i]);
    if (n == 1)
    {
        if (w == a[0])
        {
            printf ("Yes\n");
            forn (i, a[0] * 2)
                printf ("1 ");
            printf ("\n");
        }
        else
            printf ("No\n");
        return 0;
    }
    int m = a[0];
    forn (i, n)
        m = min (m, a[i]);
    int s = 0;
    forn (i, n)
        s += a[i];
    if (w > s)
    {
        cout << "No" << endl;
        return 0;
    }
    if (m <= w)
    {
        cout << "Yes" << endl;
        int num = -1;
        forn (i, n)
            if (m == a[i])
                num = i;
        write (num);
        int waste = s - w;
        forn (i, n)
            if (i != num)
                while (a[i] > 0 && waste > 0)
                {
                    a[i] --;
                    waste --;
                    write (i);
                    write (i);
                }
        write (num);
        a[num] --;
        while (a[num] > 0)
        {
            a[num] --;
            write (num);
            write (num);
        }
        forn (i, n)
            if (i != num)
                while (a[i] > 0)
                {
                    a[i] --;
                    write (i);
                    write (i);
                }
        printf ("\n");
    }
    else
    {
        if (w < 2)
        {
            printf ("No\n");
            return 0;
        }
        printf ("Yes\n");
        write (0);
        for (int i = 2; i < n; i ++)
            while (a[i] > 0)
            {
                a[i] --;
                write (i);
                write (i);
            }
        while (a[1] > 1)
        {
            a[1] --;
            write (1);
            write (1);
        }
        write (0);
        a[0] --;
        w -= 2;
        write (1);
        forn (i, a[0] - w)
        {
            write (0);
            write (0);
        }
        a[0] = w;
        write (1);
        forn (i, a[0] * 2)
            write (0);
        printf ("\n");          
    }
    return 0;
}