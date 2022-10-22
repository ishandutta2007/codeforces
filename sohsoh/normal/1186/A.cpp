#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main(){
    cin >> n >> m >> k;
    cout << (min(m, k) >= n ? "Yes" : "No") << endl;
}