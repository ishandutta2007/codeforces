#include<bits/stdc++.h>
using namespace std;

int n,tot;
char s[200005],t[200005];

bool check(){
	for(int i=1,cnt=0;i<=n;++i){
		if(t[i]=='(')++cnt;else --cnt;
		if(cnt<0)return false;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	if(n%2){puts("No");return 0;}
	scanf("%s",s+1);
	if(count(s+1,s+1+n,'(')!=n/2){puts("No");return 0;}
	copy(s+1,s+1+n,t+1);
	if(check()){puts("Yes");return 0;}
	int i;
	for(i=n;s[i]==')';--i);
	t[++tot]='(';
	for(int j=1;j<=n;++j)
		if(j!=i)t[++tot]=s[j];
	if(check()){puts("Yes");return 0;}
	for(i=1;s[i]=='(';++i);
	tot=0;
	for(int j=1;j<=n;++j)
		if(j!=i)t[++tot]=s[j];
	t[++tot]=')';
	if(check()){puts("Yes");return 0;}
	puts("No");
}