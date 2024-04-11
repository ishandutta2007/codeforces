#include <bits/stdc++.h>

using namespace std;
const int maxn=200001;

typedef long long ll;
int cs[maxn][26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	string line; cin>>line;
	for (int i=1; i<=n; i++) {
		for (int l=0; l<26; l++) {
			cs[i][l]=cs[i-1][l]+!!(line[i-1]-'a'==l);
		}
	}

	int nQueries; cin>>nQueries;
	for (int qq=0; qq<nQueries; qq++) {
		int qcs[26]={0};
		string q; cin>>q;
		for (char &c:q)
			qcs[c-'a']++;
		int minLength=1, maxLength=n;
		while (minLength<maxLength) {
			int mid=(maxLength+minLength)/2;
			bool works=true;
			for (int i=0; i<26; i++) {
				if (cs[mid][i]<qcs[i]) {
					works=false;
				}
			}
			if (works) {
				maxLength=mid;
			}
			else {
				minLength=mid+1;
			}
		}
		cout<<minLength<<'\n';
	}

	return 0;
}