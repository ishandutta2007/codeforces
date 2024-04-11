#include <bits/stdc++.h>

using namespace std;

int main() {
	string st; cin>>st; cin>>st;
	int n=0;
	for (char &c: st)
		if (c=='+') n++;
		else
			n=max(0, n-1);
	cout<<n<<endl;
	return 0;
}