// https://codeforces.com/blog/entry/96344?#comment-854898

// //          DO SOMETHING TODAY THAT YOUR FUTURE SELF WILL THANK YOU FOR
// // #include "bits/stdc++.h"
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")

// // #include <ext/pb_ds/assoc_container.hpp> // Common file
// // #include <ext/pb_ds/tree_policy.hpp>
// // #include <functional> // for less
// // using namespace __gnu_pbds;
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define fastio() ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define int long long
#define SZ(x) (int)x.size()
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define trav(a) for(auto p:a)cout<<p<<" ";cout<<endl;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589;
const long long INF = 1e18 + 42;
//
/*Theorems,concepts reminder:
Wilson : (p-1)! mod p = -1 or p-1, p is prime
Fermet : a^-1 mod p = a^(p-2) mod p, p is prime,a^(p-1) = 1 mod p
exteuclid, modInverse, matrixExp., sieve
Always take size of segment tree 4*n
Always prefer arrays over vectors
Always prefer ordered map and sets.
*/
inline void read (int*a, int n) {
	for (int i = 0; i < n; i++) cin >> a[i];
}
inline void read (vector<int>&a) {
	for (auto &x : a) cin >> x;
}
inline int add (int a, int b, int mod = MOD) {
	a += b; return a >= mod ? a - mod : a;
}
inline int sub (int a, int b, int mod = MOD) {
	a -= b; return a < 0 ? a + mod : a;
}
inline int mul (int a, int b, int mod = MOD) {
	return (int) ( (long long) a * b % mod);
}
inline int mpow (long long base, long long ex, int mod = MOD) {
	int res = 1;
	for (; ex > 0; ex >>= 1) {
		if (ex & 1) res = mul (res, base, mod);
		base = mul (base, base, mod);
	}
	return res;
}
inline int inv (int a, int mod = MOD) {
	return mpow (a, mod - 2, mod);
}
//







void SolveCase() {



	int n, k;
	cin >> n >> k;
	int cur = 1;
	int time = 0;
	while (cur < k) {
		cur *= 2;
		time++;
	}
	int rem = n - cur;
	if (rem > 0) {
		time += (int)ceil((double)rem / k);
	}
	cout << time << "\n";



}

signed main()
{
	fastio()

	int tt = 1; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		// cout << "Case #" << t << ": ";
		SolveCase();
	}
	// cerr << "Time : " << 1000 * ( (double) clock() ) / (double) CLOCKS_PER_SEC << "ms\n";
}