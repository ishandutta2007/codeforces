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

string s;
int n, a[100000];
char ch;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    fr(i, s.length())
        if (i % 2 == 0)
            a[n++] = s[i] - '0';
    sort(a, a + n);
    cout << a[0];
    fr(i, n - 1)
        cout << "+" << a[i + 1];

    return 0;
}