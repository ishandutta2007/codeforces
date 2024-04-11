
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	string line; cin>>line;
	int n=line.size();
	int leftIndex=0, rightIndex=n-1;
	string prefix, suffix, middle;
	while (leftIndex<=rightIndex) {
		if (rightIndex-leftIndex+1<=3) {
			middle.push_back(line[leftIndex]);
		}
		else {
			char c1=line[leftIndex], c2=line[leftIndex+1],
			c3=line[rightIndex-1], c4=line[rightIndex];
			char ans;
			if (c1==c4) {
				ans=c1;
			}
			else if (c1==c3) {
				ans=c1;
			}
			else ans=c2;
			prefix.push_back(ans);
			suffix.push_back(ans);
		}
		leftIndex+=2;
		rightIndex-=2;
	}
	for (int i=0; i<prefix.size(); i++)
		cout<<prefix[i];
	for (int i=0; i<middle.size(); i++)
		cout<<middle[i];
	for (int i=suffix.size()-1; i>=0; i--)
		cout<<suffix[i];
	cout<<'\n';

	return 0;
}