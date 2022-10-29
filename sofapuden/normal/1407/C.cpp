#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n,0);
	int gr = 1;
	for(int i = 1; i < n; ++i){
		cout << "? " << gr << " " << i+1 << endl;
		cout << "? " << i+1 << " " << gr << endl;
		int x,y; cin >> x >> y;
		if(x > y){
			v[gr-1] = x;
			gr = i+1;
		}
		else{
			v[i] = y;
		}
	}	
	v[gr-1] = n;
	cout << "!";
	for(int i : v)cout << " " << i;
	cout << endl;
}