#include <bits/stdc++.h>
using namespace std;

int v[10010];

int get(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ost;
    cin >> ost;
    return ost;
    //return v[i] % v[j];
}

int ans[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    v[1] = 1;
    v[2] = 3;
    v[3] = 2;
    int n;
    cin >> n;
    int lst = 1;
    for (int i = 2; i <= n; i++) {
        int ost1 = get(lst, i), ost2 = get(i, lst);
        if (ost1 > ost2) {
            ans[lst] = ost1;
            lst = i;
        } else ans[i] = ost2;
    }
    ans[lst] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}