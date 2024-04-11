#include <bits/stdc++.h>
using namespace std;
int main() {
int a, b;
cin >> a >> b;
if (a < b) swap(a, b);
cout << b << " " << (a - b) / 2 << "\n";
}