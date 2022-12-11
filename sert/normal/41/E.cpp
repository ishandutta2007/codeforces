#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
const clock_t t0 = clock();
const int N = 10001;
pair <int, int> e[N];
bool a[200][200], fnd, ok;
vector <pair<int, int> > ans, ta;
int bst = 0, n, v1, v2;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    cout << (n / 2) * (n - n / 2) << "\n";
    for (int i = 0; i < n / 2; i++)
        for (int j = n / 2; j < n; j++)
            cout << i + 1 << " " << j + 1 << "\n";
    return 0;
}