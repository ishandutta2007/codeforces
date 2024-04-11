#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i ++) {
        int x;
        a[i] = 0;
        for(int j = 0; j < 4; j ++) cin >> x, a[i] += x;
    }
    vector <int> b(n);
    for(int i = 0; i < n; i ++) b[i] = i;
    sort(b.begin(), b.end(), [&](int i, int j) {return a[i] == a[j] ? i < j : a[i] > a[j];});
    for(int i = 0; i < n; i ++) if(b[i] == 0) {
        cout << i+1 << endl;
        return 0;
    }
}