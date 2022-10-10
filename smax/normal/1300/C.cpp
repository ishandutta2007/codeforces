#include <bits/stdc++.h>
using namespace std;

int a[100000];
bool visited[100000] = {};
vector<int> bit[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<31; j++)
            if (a[i] & (1 << j))
                bit[j].push_back(i);
    }

    for (int j=30; j>=0; j--) {
        int numAvailable = 0;
        int print = -1;
        for (int i : bit[j])
            if (!visited[i]) {
                numAvailable++;
                print = i;
            }
        if (numAvailable == 1) {
            cout << a[print] << " ";
            visited[print] = true;
        }
    }
    for (int i=0; i<n; i++)
        if (!visited[i])
            cout << a[i] << " ";
    cout << "\n";

    return 0;
}