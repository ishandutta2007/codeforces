#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	char a, b;
	int aa, bb;
	cin >> a >> aa >> b >> bb;
	cout << max(abs(aa-bb),abs(a-b)) << '\n';
	while(a != b || aa != bb){
		if(a > b)cout << 'L',a--;
		if(a < b)cout << 'R',a++;
		if(aa > bb)cout << 'D',aa--;
		if(aa < bb)cout << 'U',aa++;
		cout << '\n';
	}

}