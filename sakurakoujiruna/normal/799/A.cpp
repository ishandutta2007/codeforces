#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

ll n, t, k, d; 

int main() {
	cin>>n>>t>>k>>d; 
	ll t1 = ((n-1)/k+1)*t; 
	if (t1 > d && (t1-1)/t*k + (t1-1-d)/t*k >= n) puts( "YES" ); 
	else puts( "NO" ); 
	return 0;
}