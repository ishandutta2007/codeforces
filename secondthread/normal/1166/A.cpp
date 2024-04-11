#include <bits/stdc++.h>

using namespace std;

int c1[26], c2[26];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<string> students;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		students.push_back(s);
	}
	sort(students.begin(), students.end());
	int ans=0;
	for (int i=0; i<n; i++) {
		int ind=students[i][0]-'a';
		if (i%2==0) {
			ans+=c1[ind];
			c1[ind]++;
		}
		else {
			ans+=c2[ind];
			c2[ind]++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}