#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cmi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[cmi])
            cmi = i;
    }
    for (int i = 0; i < cmi; i++) {
        if (a[i] < a[i+1])
            continue;
        cout << "NO" << endl;
        return 0;
    }
    for (int i = cmi+1; i < n; i++) {
        if (a[i] < a[i-1])
            continue;
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}