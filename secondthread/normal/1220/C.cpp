#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin>>s;
	char earliestSeen='z';
	for (char c:s) {
		cout<<(earliestSeen<c?"Ann":"Mike")<<endl;
		earliestSeen=min((int)earliestSeen, (int)c);
	}
	return 0;
}