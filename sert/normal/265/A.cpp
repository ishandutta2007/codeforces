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

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef double ld;
const ll N = 103;

string s, t;
int uk;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s >> t;
    fr(i, t.length())
        if (t[i] == s[uk])
            uk++;
    cout << uk + 1;
    return 0;
}