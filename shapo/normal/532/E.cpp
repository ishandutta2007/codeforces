#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

string s, t; 

int check(string ss) {
    int js = 0, jt = 0; 
    int wass = 0, wast = 0; 
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] == s[js]) {
            js ++; 
        } else 
        if (ss[i] != s[js]) {
            if (wass) return 0; 
            wass = 1; 
        }

        if (ss[i] == t[jt]) {
            jt ++; 
        } else 
        if (ss[i] != t[jt]) {
            if (wast) return 0; 
            wast = 1; 
        }
    }
    return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    // ios::sync_with_stdio(false);

    int n;
    cin >> n >> s >> t; 

    string sbeg = "", send = ""; 

    int i = 0; 
    for (; i < n; i++) {
        if (s[i] != t[i]) break; 
        sbeg += s[i]; 
    }

    int j = n - 1; 
    for (; j >= 0; j--) {
        if (s[j] != t[j]) break; 
        send += s[j]; 
    }

    reverse(send.begin(), send.end());

    string ss = sbeg; 
    string tt = sbeg; 

    for(int x = i; x <= j; x++) {
        ss += s[x]; 
        tt += t[x]; 
    }

    ss += t[j]; 
    tt += s[j]; 

    ss += send; 
    tt += send; 

    //cout << ss << "\n" << tt << "\n"; 

    int res = 0; 
    res += check(ss) + check(tt); 

    cout << res << "\n"; 

    return 0;
}