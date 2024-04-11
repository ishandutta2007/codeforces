#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while (T--) {
		string s1, s2; cin>>s2>>s1;
		if (s2.length()>s1.length()) {
			cout<<"NO\n";
			continue;
		}
		s1.push_back('$');
		s2.push_back('$');
		int s1Ind=0;
		bool possible=true;
		for (int i=0; i<s2.length(); i++) {
			while (s1Ind<s1.length()&&s1[s1Ind]!=s2[i]) {
				if (i==0||s1[s1Ind]!=s2[i-1]) possible=false;	
				s1Ind++;
			}
			if (s1Ind>=s1.length())
				possible=false;
			s1Ind++;
		}
		cout<<(possible?"YES":"NO")<<'\n';
	}

	return 0;
}