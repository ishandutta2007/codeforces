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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int l1, l2, r1, r2;
int len[50];

int calc(int n, int l, int c){
    int w = len[n-1];
//  cerr << n << " " << l << " " << c << " " << n << endl;
    if (c == n){
        if (l < w)
            return w;
        else
            return len[n] + 1 + len[n-1];
    }
    if (l < w)
        return calc(n-1, l, c);
    else
        return calc(n-1, l - w - 1, c) + w + 1;
}

int get(int l, int c, int cnt){
    int res = l - 1;
    forn(i, cnt){
        res = calc(30, res, c);
        res ++;
    }
    return res - 1;
        
}

int main ()
{
    len[0] = 0;
    for (int i = 1; i < 35; i ++)
        len[i] = len[i-1] * 2 + 1;

    
    
/*  string s4 = "abacabadabacaba";
    cerr << calc(30, 1, 2) << endl; 
    cerr << get(0, 1, 1) << endl; 

    return 0;
*/


    cin >> l1 >> r1 >> l2 >> r2;
    l1--; r1--; l2--; r2--;
    int res = 0;

    for (int i = 1; i <= 30; i ++){
        for (int j = 1; j <= 3; j ++)
            for (int k = 1; k <= 3; k ++){
                int s1 = get(l1, i, j);
                int s2 = get(l2, i, k);
                int bef = min(len[i-1], min(s1 - l1, s2 - l2));
                int aft = min(len[i-1], min(r1 - s1, r2 - s2));
                
                if (bef >= 0 && aft >= 0 && res < bef + aft + 1){
                    res = bef + aft + 1;
//                  cerr << i << " " << j << " " << k << endl;
//                  cerr << s1 << " " << s2 << endl;
//                  cerr << bef << " " << aft << endl;
                }
            }
    }
    cout << res << endl;
        


    

    return 0;
}