#include <iostream>
#include <vector>

using namespace std;

const int N = 5014;

vector <int> p;
bool u[N];
int n, k;

int main() {
    cin >> n >> k;
    u[0] = u[1] = true;
    for (int i = 2; i <= n; i++)
        if (!u[i]) {
            p.push_back(i);
            for (int j = i * i; j <= n * 3; j += i)
                u[j] = true;
        }
    for (int i = 0; i < p.size() - 1; i++)
        if (!u[p[i] + p[i + 1] + 1] & p[i] + p[i + 1] + 1 <= n) {
            k--;
        }
    if (k <= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}