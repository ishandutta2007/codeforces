#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 34;

string home, away;
char c1, c2;
int a[100], b[100], c, n, m, num;

int main() {
   // freopen("a.in", "r", stdin);
    cin >> home >> away;
    cin >> n;
    while (n--) {
        cin >> m >> c1 >> num >> c2;
        if (c1 == 'h') {
            a[num] += (c2 == 'y' ? 1 : 2);
            if (a[num] >= 2 && a[num] <= 30) {
                cout << home << " " << num << " " << m << "\n";
                a[num] = 34;
            }
        } else {
            b[num] += (c2 == 'y' ? 1 : 2);
            if (b[num] >= 2 && b[num] <= 34) {
                cout << away << " " << num << " " << m << "\n";
                b[num] = 34;
            }
        }
    }
}