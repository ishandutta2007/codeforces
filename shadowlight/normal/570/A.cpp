#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m, h;
    cin >> m >> n;
    vector <int> vote(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        int maxn = -1;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            if (x > maxn) {
                maxn = x;
                h = j;
            }
        }
        vote[h]++;
    }
    int maxn = -1;
    for (int i = 1; i <= m; i++) {
        if (vote[i] > maxn) {
            maxn = vote[i];
            h = i;
        }
    }
    cout << h;
}