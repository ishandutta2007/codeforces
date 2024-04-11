#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n,0);
	cout << "? 1 2" << endl;
	cout << "? 1 3" << endl;
	cout << "? 2 3" << endl;
	int x,y,z;
	cin >> x >> y >> z;
	v[0] = (x+y-z)/2;
	v[1] = (x+z-y)/2;
	v[2] = (z+y-x)/2;
	for(int i = 3; i < n; ++i){
		cout << "? " << i+1 << " " << i << endl;
		int ret; cin >> ret;
		v[i] = ret-v[i-1];
	}
	cout << "!";
	for(auto x : v)cout << " " << x;
	cout << endl;
	
}