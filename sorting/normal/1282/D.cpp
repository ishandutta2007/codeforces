#include <bits/stdc++.h>

using namespace std;

char rev(char c){
	return (c == 'a' ? 'b' : 'a');
}

int query(const string s){
	cout << s << "\n";
	fflush(stdout);

	int ret;
	cin >> ret;

	if(!ret)
		exit(0);

	return ret;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int n = query("a") + 1;
	string s = "a";
	for(int i = 1; i < n; ++i)
		s += "b";

	if(n == 301){
		s = "";
		for(int i = 0; i < n - 1; ++i)
			s += "b";

		query(s);
		return 0;
	}

	int cnt = query(s);
	if(cnt == 1){
		string s2 = "";
		for(int i = 0; i < n - 1; ++i)
			s2 += 'b';
		if(!query(s2))
			return 0;

		//s[0] = rev(s[0]);
		for(int i = 1; i < n; ++i){
			s[i] = rev(s[i]);
			query(s);
			s[i] = rev(s[i]);
		}

		return 0;
	}

	for(int i = 0; i < n - 1; ++i){
		s[i] = rev(s[i]);
		int curr = query(s);

		if(curr < cnt)
			cnt = curr;
		else
			s[i] = rev(s[i]);
	}

	if(cnt)
		s[n - 1] = rev(s[n - 1]);

	query(s);

	return 0;
}