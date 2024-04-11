#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int q;
    cin >> q;
    while(q--) {
        ll n, m, sum = 0;
        cin >> n >> m;
        ll pcnt = n / m;
        for(int i = 0; i < 10; i++)
            sum += (m * i)%10;
        sum *= (pcnt / 10);
        for(int i = 1; i <= pcnt % 10; i++)
            sum += (m * i)%10;
        cout << sum << '\n';
    }
}