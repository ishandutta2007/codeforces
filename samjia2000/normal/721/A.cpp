#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long LL;
typedef double db;

int n;
char s[110];
int ans;
int a[110];

int main(){
	scanf("%d",&n);
	char lst=' ';
	fo(i,1,n){
		char ch;
		while(ch=getchar(),ch!='B'&&ch!='W');
		if(lst!='B'&&ch=='B')ans++;
		if (ch=='B')a[ans]++;
		lst=ch;
	}
	printf("%d\n",ans);
	if (ans){
		fo(i,1,ans-1)printf("%d ",a[i]);
		printf("%d\n",a[ans]);
	}
	return 0;
}