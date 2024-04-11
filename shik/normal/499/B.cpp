#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 3010, M = 3010;
string a[M], b[M], s;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) {
        cin >> s;
        int j = find(a, a + m, s) - a;
        if (b[j].size() < s.size()) s = b[j];
        cout << s << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}