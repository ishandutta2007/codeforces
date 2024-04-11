#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
int l[N], r[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    sort(l, l + n);
    sort(r, r + n);
    ll res = n;
    for(int i = 0; i < n; i++){
        res += max(l[i], r[i]);
    }
    cout << res << endl;
}