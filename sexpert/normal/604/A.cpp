#include <bits/stdc++.h>
using namespace std;

int m[5], w[5];

int main() {
    for(int i = 0; i < 5; i++)
        cin >> m[i];
    for(int i = 0; i < 5; i++)
        cin >> w[i];
    int sc = 0;
    for(int i = 0; i < 5; i++) {
        int x = 500*(i + 1);
        sc += max(3*x/10, x - m[i]*x/250 - 50*w[i]);
    }
    int s, u;
    cin >> s >> u;
    cout << sc + 100*s - 50*u << endl;
}