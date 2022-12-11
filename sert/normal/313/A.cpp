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

string s, k;
int n = -1, a[100000];
ll ans;
char ch;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    if (s[0] == '-')
        if (s[s.length() - 1] < s[s.length() - 2])
            n = s.length() - 2;
        else
            n = s.length() - 1;
    fr(i, s.length())
        if (i != n)
            k += s[i];
    if (k == "-0")
        k = "0";
    cout << k;
    return 0;
}