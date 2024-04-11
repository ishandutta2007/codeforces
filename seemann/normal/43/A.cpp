#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long

const int INF = 1000000000;
const double EPS = 1e-8;
using namespace std;


map <string, int> a;
string b[3];
int cb = 0;
int main()
{
    int n;
    cin >> n >> ws;
    FOR(i, n)
    {
        string s;
        cin >> s;
        if (a.find(s) == a.end()) {a[s] = 0;b[cb++] = s;}
        a[s]++;
    }
    if (a[b[0]] > a[b[1]]) cout << b[0]; else cout << b[1];

}