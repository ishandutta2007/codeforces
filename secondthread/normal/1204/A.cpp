#include<bits/stdc++.h>
using namespace std;

int main() {
	string line; cin>>line;
	bool special=false;
	if (line.size()%2==1) {
		special=true;
		for (int i=1; i<line.size(); i++) {
			if (line[i]!='0') special=false;
		}
	}
	if (special)
		cout<<line.size()/2<<'\n';
	else
		cout<<(line.size()+1)/2<<'\n';

	return 0;
}