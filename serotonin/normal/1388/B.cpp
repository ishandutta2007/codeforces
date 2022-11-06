#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n;
   scanf("%d", &n);
   int x = (n + 3) / 4;
   for(int i=0; i<n-x; i++) printf("9");
   for(int i=0; i<x; i++) printf("8");
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}