#include <bits/stdc++.h>
using namespace std;
const int N=502;
int T; char s[N];
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		vector<int> v;
		for(int i=1,j=1;i<=n;i=j){
			while(j<=n && s[j]==s[i]) ++j;
			if(s[i]=='1')v.push_back(j-i);
		}
		sort(v.begin(),v.end()); reverse(v.begin(),v.end());
		int ans=0;
		for(int i=0;i<v.size();i+=2)ans+=v[i];
		printf("%d\n", ans);
	}
}