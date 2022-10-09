#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fordab(i, a, b) for(int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define PI 3.1415926535897932
#define INF 1000000000

int n;
vector<int> ans, neg;
bool zero = false;

int main() {
    cin >> n;
    forn (i, n) {
        int a;
        cin >> a;
        if (!a) {
            zero = true;
            continue;
        }
        if (a > 0) {
            ans.pb(a);
        } else {
            neg.pb(a);
        }
    }
    if (neg.size() <= 1 && !ans.size()) {
        if (zero) {
            cout << 0;
        } else {
            cout << neg[neg.size() - 1];
        }
        return 0;
    }
    if (neg.size() % 2) {
        sort(neg.begin(), neg.end());
        neg.pop_back();
    }
    forn (i, neg.size()) {
        ans.pb(neg[i]);
    }
    forn (i, ans.size()) {
        cout << ans[i] << ' ';
    }
}