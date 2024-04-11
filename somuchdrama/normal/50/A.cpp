#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    cout << (n * m - (n * m) % 2) / 2;
    return 0;
}