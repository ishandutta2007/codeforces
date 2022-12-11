#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

int main(){
	char s[2];
	scanf("%s",s);
	bool ans=0;
	fo(i,1,5){
		char t[2];
		scanf("%s",t);
		ans|=(t[0]==s[0]);
		ans|=(t[1]==s[1]);
	}
	if (ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}