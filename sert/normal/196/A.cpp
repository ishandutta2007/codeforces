#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

string s;
vector <int> es[N];
int last = -1;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) es[s[i] - 'a'].push_back(i);
    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < es[i].size(); j++)
            if (es[i][j] > last) {
                last = es[i][j];
                printf("%c", char('a' + i));
            }

    return 0;
}