#pragma comment(linker, "/STACK:100000000")
#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O500")
#define _USE_MATH_DEFINES
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <istream>
#include <fstream>
#include <climits>
#include <complex>
#include <memory>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex <ld> cd;

const bool db = false;

#define fs first
#define sd second
#define mp make_pair
#define pb push_back
#define ppb pop_back

#define inf 1000000007
#define nmax 100100
#define mmax 100100
#define eps 1e-12

pair<int, int> a[nmax];

int b[nmax];

map<int, deque<pair<int, int> > > d;

map<int, int> dd;

int main()
{
#ifdef Ahoma
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].fs >> a[i].sd;
        d[a[i].sd - a[i].fs].push_back(a[i]);
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> b[i];
        dd[b[i]]++;
    }
    for (int i = 1;i <= n;i++)
    {
        if (dd[b[i]] != d[b[i]].size())
        {
            cout << "NO\n";
            return 0;
        }
    }
    for (auto& i : d)
    {
        sort(i.sd.begin(), i.sd.end());
    }
    vector<pair<int, int> > pos;
    for (int i = 1;i <= n;i++)
    {
            pos.push_back(d[b[i]].front());
            d[b[i]].pop_front();
    }
    int a = pos[0].fs, b = pos[0].sd;
    for (int i = 1;i < n;i++)
    {
        if (pos[i].fs <= a  && pos[i].sd <= b)
        {
            cout << "NO\n";
            return 0;
        }
        a = pos[i].fs, b = pos[i].sd;
    }
    cout << "YES\n";
    for (int i = 0;i < n;i++)
    {
        cout << pos[i].fs << ' ' << pos[i].sd << '\n';
    }
    return 0;
}