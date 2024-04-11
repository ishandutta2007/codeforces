#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
int t;
cin >> t;
while(t--) {
long long a, b;
cin >> a >> b;

cout << min(max(a, 2 * b) * max(a, 2 * b), max(2 * a, b) * max(2 * a, b)) << endl;
}
}