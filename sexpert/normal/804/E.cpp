#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> k4 = {{1, 2}, {3, 4}, {1, 3}, {2, 4}, {1, 4}, {2, 3}};
vector<int> bip = {2, 1, 4, 3, 4, 3, 2, 1, 3, 4, 1, 2, 1, 2, 3, 4};
vector<ii> k5 = {{4, 0}, {3, 4}, {3, 0}, {2, 0}, {1, 2}, {1, 0}, {1, 3}, {2, 4}, {1, 4}, {2, 3}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1) {
        cout << "YES\n";
        return 0;
    }
    if(n % 4 == 2 || n % 4 == 3) {
        cout << "NO\n";
        return 0;
    }
    if(n % 4 == 0) {
        cout << "YES\n";
        for(int m = 0; m < n; m += 4) {
            for(auto p : k4)
                cout << m + p.first << " " << m + p.second << '\n';
        }
        for(int p = 0; p < n; p += 4) {
            for(int q = p + 4; q < n; q += 4) {
                for(int i = 0; i < 16; i++) {
                    cout << p + (i%4) + 1 << " " << q + bip[i] << '\n';
                }
            }
        }
    }
    if(n % 4 == 1) {
        cout << "YES\n";

        for(int m = 0; m < n - 1; m += 4) {
            for(auto p : k5) {
                int a = p.first;
                int b = p.second;
                a += m;
                if(b == 0) b = n;
                else
                    b += m;
                cout << a << " " << b << '\n';
            }
        }


        for(int p = 0; p < n - 1; p += 4) {
            for(int q = p + 4; q < n - 1; q += 4) {
                for(int i = 0; i < 16; i++) {
                    cout << p + (i%4) + 1 << " " << q + bip[i] << '\n';
                }
            }
        }
    }
}