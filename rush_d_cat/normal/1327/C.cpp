#include <bits/stdc++.h>
using namespace std;
const int N=202;
int n,m,k;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	vector<char> ans;
	for(int i=1;i<n;i++) ans.push_back('U');
	for(int i=1;i<m;i++) ans.push_back('L');
	
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<m;j++) ans.push_back('R');
			ans.push_back('D');
		} else {
			for(int j=1;j<m;j++) ans.push_back('L');
			ans.push_back('D');
		}
	}
	printf("%d\n", ans.size());
	for(auto c: ans) printf("%c", c); printf("\n");
}