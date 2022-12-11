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


map <char, int> a;
string b[3];
int cb = 0;
void _kill()
{
    cout << "NO";
    exit(0);
}
int main()
{
    int n;
    string s;
    getline(cin, s);
    cin >>ws;
    FOR(i, s.length())
    {
        if (s[i] == ' ') continue;
        if (a.find(s[i]) == a.end()) a[s[i]] = 0;
        a[s[i]]++;
    }
    getline(cin, s);
    FOR(i, s.length())
    {
        if (s[i] == ' ') continue;
        if (a.find(s[i]) == a.end()) _kill();
        a[s[i]]--;
        if (a[s[i]] < 0) _kill();
    }
    cout << "YES";
    return 0;

}