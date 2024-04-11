#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n);
        bool needTwo = false;
        for (int i=1; i<n; i++)
            if (a[i] == a[i-1] + 1)
                needTwo = true;

        cout << (needTwo ? 2 : 1) << "\n";
    }

    return 0;
}