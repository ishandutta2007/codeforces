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


map<string, int> res;
int n;

int main ()
{
    int n;
    cin >> n;
    res["void"] = 0;
    res["errtype"] = -1;
    forn(qwe, n){
        string s, t, v, now;
        cin >> s;
        if (s.size() == 7){
            cin >> t >> v;
            now = "";
            int cnt = 0;
            bool bad = 0;
            forn(i, t.size()){
                if (i > 0 && t[i] == '&' & t[i-1] != '&')
                    bad = 1;
                if (i + 1 < t.size() && t[i] == '*' && t[i+1] != '*')
                    bad = 1;
            }
            forn(i, t.size())
                if (t[i] == '*')
                    cnt ++;
                else
                if (t[i] == '&')
                    cnt --;
                else
                    now += t[i];
                
            if (bad || res.count(now) == 0 || res[now] < 0)
                res[v] = -1;
            else
                res[v] = max(-1, cnt + res[now]);
          }else{
            cin >> t;
            now = "";
            int cnt = 0;
            bool bad = 0;
            forn(i, t.size()){
                if (i > 0 && t[i] == '&' & t[i-1] != '&')
                    bad = 1;
                if (i + 1 < t.size() && t[i] == '*' && t[i+1] != '*')
                    bad = 1;
            }
            forn(i, t.size())
                if (t[i] == '*')
                    cnt ++;
                else
                if (t[i] == '&')
                    cnt --;
                else
                    now += t[i];
            if (bad || res.count(now) == 0 || res[now] < 0 || res[now] + cnt < 0)
                puts("errtype");    
            else{
                cout << "void";
                forn(i, res[now] + cnt)
                    printf("*");
                puts("");
            }
          }
    }


        return 0;
}