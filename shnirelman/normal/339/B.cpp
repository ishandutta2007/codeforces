#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int i  =0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }


    long long ans = 0;
    int lst = 0;
    for(int i = 0; i < m; i++) {
        if(a[i] >= lst)
            ans += a[i] - lst;
        else
            ans += n - lst + a[i];
        lst = a[i];
//        ans += min(max(a[i], lst) - min(a[i], lst), n - max(a[i], lst) + min(a[i], lst));
    }

    cout << ans << endl;
}