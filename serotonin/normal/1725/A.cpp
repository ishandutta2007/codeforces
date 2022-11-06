#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int main() {
   ll n, m;
   cin >> n >> m;
   if(n == 1 or m == 1) cout << n * m - 1;
   else cout << (m - 1) * n;
}