#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = sqrt(n+0.5);
    int q = n / m, r = n % m;
    vector <int> a(n);
    for(int i = 0; i < n; i ++) a[i] = i+1;
    int x = 0;
    for(int i = 0; i < m-r; i ++) reverse(a.begin()+x, a.begin()+x+q), x+=q;
    for(int i = 0; i < r; i ++) reverse(a.begin()+x, a.begin()+x+q+1), x+=q+1;
    for(int i = 0; i < n; i ++) cout << a[i] << ' ';
    cout << endl;
}