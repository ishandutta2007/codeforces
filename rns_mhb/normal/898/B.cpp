#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{

    //freopen("input.txt", "r", stdin);

    cin >> n >> a >> b;

    for(int i = 0; i <= n / a; i++)
        if ((n - a * i) % b == 0) {
            cout << "YES" << endl << i << " " << (n - a * i) / b;
            return 0;
        }

    cout << "NO";

}