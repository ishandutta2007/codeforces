#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		string s, t, q; cin>>s>>t>>q;
		int have[26]={0};
		for (char &c:q) have[c-'a']++;
		bool possible=true;
		if (s.size()>t.size())
			possible=false;
		int sIndex=0;
		for (char &c:t) {
			if (sIndex<s.size() && s[sIndex]==c)
				sIndex++;
			else if (have[c-'a']>0)
				have[c-'a']--;
			else
				possible=false;
		}
		if (sIndex!=s.size())
			possible=false;
		if (possible) cout<<"YES\n";
		else cout<<"NO\n";

	}

	return 0;
}