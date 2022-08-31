#include <iostream>
#include <algorithm>
int main() { int a, b; std :: cin >> a >> b; std :: cout << std :: __gcd (a - 1, b - 1) + 1 << "\n"; return 0; }