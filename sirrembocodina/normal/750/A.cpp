#include <iostream> 

using namespace std;

int main() {
int n, k;
cin >> n >> k;
k = 240 - k;
for (int I = 0; I < n; ++I) {
k -= I * 5 + 5;
if (k < 0) {
cout << I;
return 0;
}
}
cout << n;
}