#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ptr = 0, rem = 0, ans = 0;
    while(ptr < n) {
        if(a[ptr] <= rem) {
            rem -= a[ptr];
            ptr++;
        }
        else {
            ans++;
            rem = m;
        }
    }
    cout << ans << endl;
}