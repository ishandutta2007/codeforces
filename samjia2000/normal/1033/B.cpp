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
	for(int T=get();T;T--){
		LL a,b;
		cin>>a>>b;
		if (a==b+1){
			LL v=a+b;
			bool prime=1;
			fo(i,2,sqrt(v))
			if(v%i==0)prime=0;
			if (prime)printf("YES\n");else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}