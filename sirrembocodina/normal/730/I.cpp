#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>

#define fs first
#define sc second

using namespace std;

int a[3100], b[3100];
int ansa[3100], ansb[3100];
pair<int, int> x[3100];

int main()
{
    int n, p, s;
    cin >> n >> p >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < p + s; ++i) {
        x[i] = make_pair(b[i] - a[i], i);
    }
    sort(x, x + p + s);
    for (int i = p + s; i < n; ++i) {
        x[p + s] = make_pair(b[i] - a[i], i);
        sort(x, x + p + s + 1);
        int suma = 0, sumb = 0;
        for (int j = 0; j < p; ++j) {
            suma += a[x[j].sc];
        }
        for (int j = p + 1; j < p + s + 1; ++j) {
            sumb += b[x[j].sc];
        }
        int ans = 0, res = 0;
        for (int j = 0; j < p + s + 1; ++j) {
            int cur = suma + sumb;
            if (j < p) {
                cur -= a[x[j].sc];
                cur += a[x[p].sc];
            }
            if (j >= p + 1) {
                cur -= b[x[j].sc];
                cur += b[x[p].sc];
            }
            if (res < cur) {
                res = cur;
                ans = j;
            }
        }
        for (int j = ans; j < p + s; ++j) {
            x[j] = x[j + 1];
        }
    }
    for (int i = 0; i < p; ++i) {
        ansa[i] = x[i].sc;
    }
    for (int i = p; i < p + s; ++i) {
        ansb[i - p] = x[i].sc;
    }
    int sum = 0;
    for (int i = 0; i < p; ++i) {
        sum += a[ansa[i]];
    }
    for (int i = 0; i < s; ++i) {
        sum += b[ansb[i]];
    }
    cout << sum << endl;
    for (int i = 0; i < p; ++i) {
        cout << ansa[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < s; ++i) {
        cout << ansb[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}