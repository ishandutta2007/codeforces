#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ei = (n + 3)/4;
        for(int i = 0; i < n - ei; i++)
            cout << "9";
        for(int i = 0; i < ei; i++)
            cout << "8";
        cout << '\n';
    }
}