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
	int n=get();
	int l=0,r=1e9;
	char c0;
	fo(i,1,n){
		if (i==1){
			printf("0 0\n");fflush(stdout);
			char s[20];
			scanf("%s",s+1);
			c0=s[1];
			continue;
		}
		int mid=(l+r)/2;
		printf("%d 0\n",mid);fflush(stdout);
		char s[20];
		scanf("%s",s+1);
		if (s[1]==c0)l=mid;
		else r=mid;
	}
	if (l+2<=1e9)printf("%d %d %d %d\n",l+1,1,l+2,4);
	else printf("%d %d %d %d\n",l,1,l-1,4);
	fflush(stdout);
	return 0;
}