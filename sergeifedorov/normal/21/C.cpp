#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second


const string task = "";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 100100;

int n;
int a[nmax], ss[nmax], sp[nmax], c1[nmax];

int main(){
//     freopen(inp.data(), "rt", stdin);
//     freopen(oup.data(), "wt", stdout);
    
    scanf("%d", &n);
    int s = 0;
    forn(i,n){
    scanf("%d", &a[i]);
    s += a[i];
    }
    if (s % 3 != 0){
    puts("0");
    exit(0);
    }
    s /= 3;
    
    long long res = 0;
    
    sp[0] = 0;
    forn(i,n)
    sp[i+1] = sp[i] + a[i];
    forn(i,n)
    if (i > 0 && sp[i] == s)
        c1[i-1] = 1;
/*    forn(i,n)
    cerr << c1[i] << " ";
    cerr << endl;*/
    forn(i,n)
    c1[i+1] += c1[i];
        
    ss[n] = 0;
    ford(i,n){
//  cerr << i << " " << res << " " << c1[i-1]<<endl;
    ss[i] = ss[i+1] + a[i];
    if (i > 0 && ss[i] == s)
        res += c1[i-2];
    }
    cout <<res << endl;
    
    
    return 0;
}