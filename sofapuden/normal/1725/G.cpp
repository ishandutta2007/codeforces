#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	n--;
	if(n <= 1)cout << "35"[n] << '\n';
	else cout << 4*((n-2)/3)+((n-2)%3) + 7 << '\n';
}