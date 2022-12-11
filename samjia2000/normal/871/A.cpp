#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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
		int n=get();
		int ans;
		if (n<=3)ans=-1;
		else{
			ans=n/4;
			if (n%4==1){
				if (n==5)ans=-1;
				else ans=ans-1;
			}
			if (n%4==3){
				if (ans<3)ans=-1;
				else ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}