#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>
#include <string>
using namespace std;
const int N = 1e5 + 34;
int n, ca, cb;
bool ua[N], ub[N];
int a[N], b[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n / 2; i++)
        ua[i] = ub[i] = true;
    for (int i = 0; i < n; i++) 
        if (a[ca] < b[cb]) 
            ua[ca++] = true;
        else
            ub[cb++] = true;
    for (int i = 0; i < n; i++)
        cout << int(ua[i]);
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << int(ub[i]);
    cout << "\n";
    return 0;
}