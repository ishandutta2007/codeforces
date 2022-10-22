#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    //int a[200000];
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());
    /*for (int i = 0; i < n; i++)
        cout << a[i] << " ";*/
    long long x = 0;
    long long y = 1;
    a.push_back(2000000001);
    long long pai = 0;
    while (y < n) {
        //cout << x << " " << y << endl;
        while (a[y] <= 2*a[x])
            y++;
        y--;
        if (y == x) {
            y++;
            x++;
            continue;
        }
        pai += (y-x);
        x++;
    }
    cout << pai << endl;
    return 0;
}