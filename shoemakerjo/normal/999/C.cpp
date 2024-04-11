#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> inds(26);

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = n-1; i >= 0; i--) inds[s[i]-'a'].push_back(i);
	while(k--)
	{
		for(int i = 0; i < 26; i++) {
			if (inds[i].size()) {
				s[inds[i].back()] = '$';
				inds[i].pop_back();
				break;
			}
		}
	}
	for (char stuff : s) {
		if (stuff-'$') cout << stuff;
	}
	cout << endl;
	
}