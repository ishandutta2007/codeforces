#include<bits/stdc++.h>
#define s second
#define f first

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int su = 0;
		int x = 0;
		for(int i = 1; su < n; i+=2)su+=i,x++;
		cout << x << '\n';
	}
}