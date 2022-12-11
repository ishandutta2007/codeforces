#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 1e6 + 34;

typedef long long ll;

ll n, k;
vector <ll> cur;
ll p[N], len, sum;
set <ll> s;
ll a[N];

int main() {
    srand(3431);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (k--)
        while (true) {
            sum = 0;
            len = rand() % n + 1;
            cur.clear();
            for (int i = 0; i < len; i++) p[i] = 1;
            for (int i = len; i < n; i++) p[i] = 0;
            random_shuffle(p, p + n);
            for (int i = 0; i < n; i++)
                if (p[i]) {
                    sum += a[i];
                    cur.push_back(a[i]);
                }
            if (s.find(sum) == s.end()) {
                cout << cur.size();
                for (int i = 0; i < cur.size(); i++)
                    cout << " " << cur[i];
                cout << "\n";
                s.insert(sum);
                break;
            }
        }

    return 0;
}