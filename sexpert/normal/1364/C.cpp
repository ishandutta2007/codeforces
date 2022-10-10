#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> slots;
    int used = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > a[i - 1]) {
            b[i] = a[i - 1];
            for(int s = a[i - 1] + 1; s <= a[i] - 1; s++) {
                b[slots.back()] = s;
                slots.pop_back();
            }
        }
        else
            slots.push_back(i);
    }
    for(auto x : slots)
        b[x] = 1000000;
    for(int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << '\n';
}