#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,c[55],ans[55][55],t[55];

int l,r,rev;

inline void cal(int x){
	t[0] = 0;
	int s = n;
	for(int i=ans[x][0];i >= 1;i--){
		for(int j=s-ans[x][i]+1;j <= s;j++)
			t[++t[0]] = c[j];
		s -= ans[x][i];
	}
	memcpy(c,t,sizeof(t));
}

inline int find(int x){
	for(int i=1;i <= n;i++) 
		if(c[i] == x) return i;
	assert(0); return -1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]);
	l = r = find(1);
	for(int i=1;i < n;i++){
		int x = find(i+1);
		if(x > r){
			if(l > 1) ans[i][++ans[i][0]] = l-1;
			if(!rev) ans[i][++ans[i][0]] = r-l+1;
			else{
				for(int j=l;j <= r;j++) ans[i][++ans[i][0]] = 1;
				rev ^= 1;
			}
			ans[i][++ans[i][0]] = x-r;
			if(x < n) ans[i][++ans[i][0]] = n-x;
			
			int tmp = l;
			l = n-r+1 , r = n-tmp+1;
			l--;
		}
		else{
			if(x > 1) ans[i][++ans[i][0]] = x-1;
			ans[i][++ans[i][0]] = l-x;
			if(rev) ans[i][++ans[i][0]] = r-l+1;
			else{
				for(int j=l;j <= r;j++) ans[i][++ans[i][0]] = 1;
				rev ^= 1;
			}
			if(r < n) ans[i][++ans[i][0]] = n-r;
			
			int tmp = l;
			l = n-r+1 , r = n-tmp+1;
			r++;
		}
		cal(i);
	}
	printf("%d\n",c[1] == 1 ? n-1 : n);
	for(int i=1;i < n;i++){
		printf("%d ",ans[i][0]);
		for(int j=1;j <= ans[i][0];j++) printf("%d ",ans[i][j]);
		puts("");
	}
	if(c[1] != 1){
		printf("%d ",n);
		for(int i=1;i <= n;i++) printf("1 ");
		puts("");
	}
	return 0;
}