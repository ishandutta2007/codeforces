#include <bits/stdc++.h>

using namespace std;

string query(string s){
	cout << "? " << s << endl;
	fflush(stdout);

	cin >> s;

	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string t;

	cin >> t;

	string s1 = "", ans1;

	for(int i = 0; i < (int)t.size(); i++){
		s1 += (i % 26) + 'a';
	}

	ans1 = query(s1);

	string s2 = "", ans2;

	for(int i = 0; i < (int)t.size(); i++){
		s2 += ((i / 26) % 26) + 'a';
	}

	ans2 = query(s2);

	string s3 = "", ans3;

	for(int i = 0; i < (int)t.size(); i++){
		s3 += ((i / (26 * 26)) % 26) + 'a';
	}

	ans3 = query(s3);

	string ans_t = t;

	for(int i = 0; i < (int)t.size(); i++){
		if(s1[i] != ans1[i] || s2[i] != ans2[i] || s3[i] != ans3[i]){
			ans_t[ (ans1[i] - 'a') + (ans2[i] - 'a') * 26 + (ans3[i] - 'a') * 26 * 26 ] = t[ i ];
		}
	}

	cout << "! " << ans_t << endl;
	fflush(stdout);

	return 0;
}