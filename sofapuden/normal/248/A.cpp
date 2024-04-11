#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		a+=x;
		b+=y;
	}
	cout << min(a,n-a)+min(b,n-b) << "\n";
}