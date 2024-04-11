#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

string ff(string s) {
    s = string((int)s.length(),'0')+s;
    for (int i = 1; i < (int) s.size()-1; i ++) 
        if (s[i] == '1' && s[i+1] == '1') {
            s[i] = '0';
            s[i+1] = '0';
            s[i-1] = '1';
            i -= 3;
        }
    int x = 0;
    while (x < (int)s.length() && s[x] == '0') x ++;
    if (x == s.length()) return string(1,'0');
    return s.substr(x);
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    s = ff(s);
    t = ff(t);
    int sl = (int)s.length();
    int tl = (int)t.length();
    if (sl>tl || sl==tl && s > t) {
        puts (">");
    } else
    if (s == t) {
        puts ("=");
    } else {
        puts ("<");
    }
    return 0;
}