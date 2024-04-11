#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

multiset<string> ft, sc[20];
int n;
string s[10000];
char d;

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
        cin >> s[i];
    cin >> d;
    return true;
}

void solve()
{
    int sum = 0;
    forn (i, n)
        sum += s[i].size() + 1;
    sum -= n / 2;
    forn (i, n)
    {
        ft.insert(s[i] + d);
        sc[s[i].size()].insert(s[i]);
    }
    int line = sum * 2 / n;
    forn (i, n / 2)
    {
        cout << *ft.begin();
        string cur = *ft.begin();
        cur = cur.substr(0, cur.size() - 1);
        sc[cur.size()].erase(cur);
        int need = line - cur.size() - 1;
        ft.erase(ft.begin());
        cout << *sc[need].begin() << endl;
        ft.erase(*sc[need].begin() + d);
        sc[need].erase(sc[need].begin());
    }
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}