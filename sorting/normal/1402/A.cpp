#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    if(n == 1){
        cout << "1 1\n";
        cout << -v[1] << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";

        return 0;   
    }

    cout << 1 << " " << n << "\n";
    for(int i = 1; i < n; ++i)
        cout << -v[i] * n << " ";
    cout << "0";
    cout << "\n";

    cout << 1 << " " << n - 1 << "\n";
    for(int i = 1; i <= n - 1; ++i)
        cout << v[i] * (n - 1) << " ";
    cout << "\n";

    cout << n << " " << n << "\n";
    cout << -v[n] << "\n";
}