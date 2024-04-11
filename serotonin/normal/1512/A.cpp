#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

pair <int,int> a[sz];
#define x first
#define y second

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i].x), a[i].y = i + 1;
   sort(a, a+n);
   if(a[0].x == a[1].x) printf("%d\n", a[n-1].y);
   else printf("%d\n", a[0].y);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}