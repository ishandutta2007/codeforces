#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int num[15], a[15];

ll get(int t){
    for(int i = 0; i < n; i++) a[i] = num[i];
    int rem = a[t];
    a[t] = 0;
    int pos = (t+1) % 14;
    while(rem % 14 != 0){
        a[pos]++;
        rem--;
        pos = (pos+1) % 14;
    }
    for(int i = 0; i < n; i++) a[i] += rem / 14;

    ll res = 0;
    for(int i = 0; i < n; i++) if(a[i] % 2 == 0) res += a[i];

    return res;

}

int main() {
    n = 14;
    for(int i = 0; i < n; i++) cin >> num[i];
    ll res = 0;
    for(int i = 0; i < 14; i++) res = max(res, get(i));
    cout << res;
}