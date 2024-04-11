#include <bits/stdc++.h>

using namespace std;

int main() {
int t;cin >> t; while(t--) {
int x,y,n;
cin >> x >> y >> n;
int prik = n - n % x + y;
while (prik > n) prik -= x;
cout << prik << endl; 
}
}