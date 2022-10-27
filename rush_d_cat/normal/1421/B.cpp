#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200 + 10;
int t,n;
char s[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);


		{
			vector< pair<int,int> > ans;
			if(s[1][2]=='0') ans.push_back(make_pair(1,2));
			if(s[2][1]=='0') ans.push_back(make_pair(2,1));
			if(s[n][n-1]=='1') ans.push_back(make_pair(n,n-1));
			if(s[n-1][n]=='1') ans.push_back(make_pair(n-1,n));
			if(ans.size()<=2) {
				printf("%d\n", ans.size());
				for(auto p:ans){
					printf("%d %d\n", p.first,p.second);
				}
				continue;
			}
		}


		{
			vector< pair<int,int> > ans;
			if(s[1][2]=='1') ans.push_back(make_pair(1,2));
			if(s[2][1]=='1') ans.push_back(make_pair(2,1));
			if(s[n][n-1]=='0') ans.push_back(make_pair(n,n-1));
			if(s[n-1][n]=='0') ans.push_back(make_pair(n-1,n));
			if(ans.size()<=2) {
				printf("%d\n", ans.size());
				for(auto p:ans){
					printf("%d %d\n", p.first,p.second);
				}
				continue;
			}
		}

	}
}