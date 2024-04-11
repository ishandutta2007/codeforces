#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 200005;
int n , a[N] , b[N] , p[N];
string s[N] , t[N];
vector<string> V;

void work() {
    int i;
    cin >> n;
    for (i = 0 ; i < n; ++ i) {
        cin >> s[i] >> t[i];
        V.push_back(s[i]);
        V.push_back(t[i]);
    }
    sort(V.begin() , V.end());
    for (i = 0 ; i < n ; ++ i) {
        a[i] = lower_bound(V.begin() , V.end() , s[i]) - V.begin();
        b[i] = lower_bound(V.begin() , V.end() , t[i]) - V.begin();
       // cout << a[i] << ' ' << b[i] << endl;
    }
    for (i = 0 ; i < n ; ++ i) {
        cin >> p[i];
        -- p[i];
    }
    int rank = -1;
    for (i = 0 ; i < n ; ++ i) {
        int x = min(a[p[i]] , b[p[i]]);
        if (x > rank)
            rank = x;
        else if (a[p[i]] + b[p[i]] - x > rank)
            rank = a[p[i]] + b[p[i]] - x;
        else
            break;
    }
    puts(i < n ? "NO" : "YES");
}

int main() {
    work();
    return 0;
}