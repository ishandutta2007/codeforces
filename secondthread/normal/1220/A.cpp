#include <bits/stdc++.h>
using namespace std;

int main() {
	int nn; cin>>nn;
	string line; cin>>line;
	int zs=0;
	for (char c:line) {
		if (c=='z') zs++;
	}
	int ones=(line.length()-4*zs)/3;
	for (int i=0; i<ones; i++)
		cout<<"1 ";
	for (int i=0; i<zs; i++)
		cout<<"0 ";
	cout<<endl;
	return 0;
}