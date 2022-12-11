#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const int N = 1e4 + 7;

vector <int> v[4];
int n, m;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        v[m - 1].push_back(i + 1);
    }
    m = min(min(v[0].size(), v[1].size()), v[2].size());

    cout << m << "\n";
    for (int i = 0; i < m; i++)
        cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << "\n";

    return 0;
}