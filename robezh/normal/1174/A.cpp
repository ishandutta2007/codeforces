#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2005;

int n;
int a[N];

int main() {
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if(a[0] != a[n - 1]) {
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    else cout << "-1";
}