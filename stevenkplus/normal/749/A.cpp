#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
cout << n/ 2 << "\n";
while (n > 0) {
int k = n == 3 ? 3 : 2;
cout << k << " ";
n -= k;
}
cout << "\n";
}