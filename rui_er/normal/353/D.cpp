//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

string s; 
int cntM, ans;

int main() {
	cin>>s;
	int l = s.length();
	for(int i=0;i<l;i++) s[i] == 'M' ? ++cntM : (!cntM ? : ans = max(ans+1, cntM));
	printf("%d\n", ans);
	return 0;
}