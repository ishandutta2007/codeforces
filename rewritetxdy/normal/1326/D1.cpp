#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
const int N = 1e6+10;

int t,nex[N];
char s[N],c[N];
stack<char>q;

inline void solve(){
	int n = strlen(s+1);
	int x=1,y=n;
	while(s[x] == s[y] && x < y)
		printf("%c",s[x]) , q.push(s[x]) , x++ , y--;
	for(int i=1;i <= y-x+1;i++)
		s[i] = s[x+i-1];
	s[y-x+2] = 0;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		solve();
		int n = strlen(s+1);
		for(int i=1;i <= n;i++)
			c[i] = s[n-i+1];
		for(int i=2,j=0;i <= n;i++){	//2 
			while(j > 0 && c[j+1] != c[i])
				j = nex[j];
			nex[i] = c[j+1] == c[i] ? ++j : 0;
		}
		int l = 0;
		for(int i=1;i <= n;i++){
			while(l && s[i] != c[l+1]) l = nex[l];
			if(s[i] == c[l+1]) l++;
		}
		
		int ans = l;
		for(int i=2,j=0;i <= n;i++){	//2 
			while(j > 0 && s[j+1] != s[i])
				j = nex[j];
			nex[i] = s[j+1] == s[i] ? ++j : 0;
		}
		l = 0;
		for(int i=1;i <= n;i++){
			while(l && c[i] != s[l+1]) l = nex[l];
			if(c[i] == s[l+1]) l++;
		}
		if(ans > l)
			for(int i=1;i <= ans;i++)
				printf("%c",c[i]);
		else
			for(int i=1;i <= l;i++)
				printf("%c",s[i]);
		while(!q.empty())
			printf("%c",q.top()) , q.pop();
		puts("");
	}
}