#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int p[maxn];
int fl[maxn]; 
vi nr;
int main() {
	ll n;
	cin>> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	ll mn = 1e12;
	for (int i = 2; i < 1e6 + 10; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			if (mn < 1e9) {
				cout << 1 << endl;
				return 0;
			}
			mn = i;
		}
	} 
	if (n != 1) {
		if (mn < 1e9) {
			cout << 1 << endl;
			return 0;
		}
		mn = min(mn, n);
	}
	cout << mn << endl;
	return 0;
}