#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	int T; cin>>T;
	while (T--) {
		string a, b; cin>>a>>b;
		int skip=0;
		while (b[b.size()-1-skip]=='0') skip++;
		int move=0;
		while (a[a.size()-1-skip-move]=='0') move++;
		cout<<move<<'\n';
	}

	return 0;
}