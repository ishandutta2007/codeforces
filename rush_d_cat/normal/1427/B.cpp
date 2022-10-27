#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k;
char s[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		bool W=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='W')W=1;

		if(W==0){
			if(k)printf("%d\n", 2*(k-1)+1); else printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='W')ans++;
			if(s[i]=='W'&&s[i-1]=='W')ans++;
		}
		//printf("ans=%d\n", ans);
		vector<int> v,v_; 
		for(int i=1,j=1;i<=n;i=j){
			if(s[i]=='W'){
				j++;
				//return 0;
			}else{
				while(j<=n&&s[j]=='L')++j;
				if(i==1||j==n+1) v_.push_back(j-i);
				else v.push_back(j-i);
			}
		}
		sort(v.begin(),v.end());
		
		for(int i=0;i<v.size();i++){
			//printf("%d\n", v[i]);
			if(k>=v[i]){
				ans+=v[i]*2+1; k-=v[i];
			}else{
				ans+=k*2; k=0;
			}
		}
		//printf("ans=%d\n", ans);

		for(int i=0;i<v_.size();i++){
			if(k>=v_[i]){
				ans+=v_[i]*2; k-=v_[i];
			}else{
				ans+=k*2; k=0;
			}
		}
		printf("%d\n", ans);
	}
}