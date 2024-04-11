#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,ans[N],cnt = 0,l=1,r=n,tt;
char c[N],s[N];


int main()
{
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		scanf("%s",c+1);
		scanf("%s",s+1);
		cnt = 0,l=1,r=n,t=0;
		for(int i=n;i >= 1;i--){
			int x = (t ? l : r),y = (t ? r : l);
			if(((c[x]-'0')^t) == s[i]-'0') t ? l++ : r--;
			else if(((c[y]-'0')^t) != s[i]-'0') ans[++cnt] = i , t ? r-- : l++ , t ^= 1;
			else ans[++cnt] = 1 , ans[++cnt] = i ,t ? r-- : l++ , t ^= 1;
		}
		printf("%d ",cnt);
		for(int i=1;i <= cnt;i++) printf("%d ",ans[i]);
		puts("");
	}
}