#include <bits/stdc++.h>
using namespace std;

int main() {
int n, k;
cin >> n >> k;
int ans = 1;
int sum = n % 10;
while (sum % 10 != 0 && sum % 10 != k) {
sum = (sum + n) % 10;
ans += 1;
}
cout << ans << "\n";
}