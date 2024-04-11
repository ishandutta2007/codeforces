#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	rep(i, 0, t) {
		int x,y;
		cin >> x >> y;
		if (x >= pow(y,2) && x%2 == y%2) {

			cout << "YES" << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}