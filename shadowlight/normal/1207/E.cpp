#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
	cout << "? ";
	for (int i = 1; i <= 100; i++) {
		cout << i << " ";
	}
	cout << endl;
	int a;
	cin >> a;
	cout << "? ";
	for (int i = 1; i <= 100; i++) {
		cout << (i << 7) << " ";
	}
	cout << endl;
	int b;
	cin >> b;
	int t = (a ^ b) % (1 << 7);
	cout << "! " << (t ^ a) << endl; 
}