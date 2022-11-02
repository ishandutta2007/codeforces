#include<bits/stdc++.h>
using namespace std;

int make(string s){
	if (s == "Tetrahedron") return 4;
	if (s == "Cube") return 6;
	if (s == "Octahedron") return 8;
	if (s == "Dodecahedron") return 12;
	if (s == "Icosahedron") return 20;
}

signed main(){
	int n, a = 0;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		a += make(s);
	}
	cout << a;
	return 0;
}