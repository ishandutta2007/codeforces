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

char buf[100100];
string s,a,b;

int go1(string &s, string &a){
    forn(i,s.size()-a.size()+1){
        bool now = 1;
        forn(j,a.size())
            if (a[j] != s[i+j]) now = 0;
        if (now)
            return i;
    }
    return 1e9;
}

int go2(string &s, string &a){
    ford(i,s.size()-a.size()+1){
        bool now = 1;
        forn(j,a.size())
            if (a[j] != s[i+j]) now = 0;
        if (now)
            return i;
    }
    return -1e9;
}


bool solve(string &s, string &a, string &b){
    int l = go1(s,a);
    int r = go2(s,b);
    if (l+(int)a.size() <= r) return 1;
    return 0;
}

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(outp.data(),"wt", stdout);
    gets(buf);
    s = buf;
    gets(buf);
    a = buf;
    gets(buf);
    b = buf;

    bool r1,r2;
    r1 = r2 = 0;
    r1 = solve(s,a,b);
    reverse(all(s));
    r2 = solve(s,a,b);
    if (r1 && r2)
        puts("both");
    if (r1 && !r2)
        puts("forward");
    if (!r1 & r2)
        puts("backward");
    if (!r1 && !r2)
        puts("fantasy");

    return 0;
}