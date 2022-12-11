#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

string s, k;
int a;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 1) continue;
        if (s[i] == '8' && k[i] == '[') a++;
        if (s[i] == '8' && k[i] == '(') a--;
        if (s[i] == '(' && k[i] == '[') a--;
        if (s[i] == '(' && k[i] == '8') a++;
        if (s[i] == '[' && k[i] == '(') a++;
        if (s[i] == '[' && k[i] == '8') a--;
    }

    if (a == 0) cout << "TIE\n";
    if (a > 0) cout << "TEAM 1 WINS\n";
    if (a < 0) cout << "TEAM 2 WINS\n";
    return 0;
}