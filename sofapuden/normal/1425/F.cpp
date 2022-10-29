#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	cout << "? 1 3" << endl;
	cout << "? 2 3" << endl;
	cout << "? 1 2" << endl;
	for(int i = 3; i < n; ++i){
		cout << "? " << i << " " << i+1 << endl;
	}
	vector<int> in(n);
	for(auto &x : in)cin >> x;
	vector<int> out(n);
	out[0] = in[0]-in[1];
	out[1] = in[2]-out[0];
	out[2] = in[0]-in[2];
	for(int i = 3; i < n; ++i){
		out[i] = in[i]-out[i-1];
	}
	cout << "!";
	for(int i = 0; i < n; ++i){
		cout << " " <<out[i];
	}
	cout << endl;
}