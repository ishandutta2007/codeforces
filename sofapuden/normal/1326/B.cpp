#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define ll long long;
using namespace std;


int main() {
	int t;
	cin >> t;
	long long max = 0;

	rep(i, 0, t) {
		long long tmp;
		cin >> tmp;
		cout << max + tmp;
		if (tmp > 0) {
			max += tmp;
		}
		if (i < t-1) {
			cout << " ";

		}
		else {
			cout << "\n";
		}
	}
}