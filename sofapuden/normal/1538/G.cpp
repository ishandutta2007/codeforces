#include<bits/stdc++.h>

using namespace std ;
typedef long long ll;
const int mxN = 1e9+1000;

int main() {
int t;cin >> t;
while(t--) {
ll x, y, a, b; cin >>x>>y>>a>>b;
if(a>b){
 swap(a, b) ;
} 
ll l = 0, r= mxN,  bes = 0;
while(l <= r) {
ll m = (l+r) /2;
if(m * a > x || m*b > y) {
r = m-1;
continue;
} 
ll z1 = m+(x-m*a) /b;
ll z2 = m+(y-m*b) /a;
bes = max(bes, min(z1, z2)) ;
if(z1 < z2) {
l=m+1;
} 
else{
r=m-1;
}
} 
cout << bes << '\n' ;
} 
}