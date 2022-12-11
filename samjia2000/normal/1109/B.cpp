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

const int N = 5005;

int n;
char s[N],t[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	bool same=1;
	fo(i,1,n/2)same&=(s[i]==s[1]);
	if (same)return printf("Impossible\n"),0;
	if (n&1)printf("2\n");
	else{
		fo(i,1,n)t[i]=s[i];
		fo(l,1,n){
			char tmp=s[1];
			fo(i,1,n-1)s[i]=s[i+1];
			s[n]=tmp;
			bool yes=1;
			fo(i,1,n)yes&=(s[i]==s[n-i+1]);
			bool all=1;
			fo(i,1,n)all&=(s[i]==t[i]);
			yes&=(!all);
			if (yes)return printf("1\n"),0;
		}
		printf("2\n");
	}
	return 0;
}