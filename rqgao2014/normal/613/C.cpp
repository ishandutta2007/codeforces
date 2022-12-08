#include<bits/stdc++.h>
using namespace std;

inline int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int n,a[30],si;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]&1) si++;
	}
	if(si>=2){
		puts("0");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
		puts("");
	}
	else if(n==1){
		printf("%d\n",a[1]);
		for(int i=1;i<=a[1];i++) putchar('a');
		puts("");
	}
	else if(si){
		int g=a[1];
		for(int i=2;i<=n;i++)
			g=gcd(g,a[i]);
		for(int i=1;i<=n;i++) a[i]/=g;
		printf("%d\n",g);
		for(int _=1;_<=g;_++){
			for(int i=1;i<=n;i++)
				if(a[i]%2==0) for(int j=1;j<=a[i]/2;j++) putchar(i+'a'-1);
			for(int i=1;i<=n;i++)
				if(a[i]&1) for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
			for(int i=n;i;i--)
				if(a[i]%2==0) for(int j=1;j<=a[i]/2;j++) putchar(i+'a'-1);
		}
		puts("");
	}
	else{
		int g=a[1];
		for(int i=2;i<=n;i++)
			g=gcd(g,a[i]);
		for(int i=1;i<=n;i++) a[i]/=g;
		printf("%d\n",g);
		for(int _=1;_<=g;_+=2){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
			for(int i=n;i;i--)
				for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
		}
		puts("");
	}
}
/*
2
6 3
*/