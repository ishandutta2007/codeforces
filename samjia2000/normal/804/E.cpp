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
#define put(x,y) printf("%d %d\n",x,y)

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
	if (n%4>1)return printf("NO\n"),0;
	printf("YES\n");
	for(int i=0;i+4<=n;i+=4){
		for(int j=i+4;j+4<=n;j+=4){
			for(int x=i;x<i+4;x+=2){
				for(int y=j;y<j+4;y+=2){
					put(x+1,y+1);
					put(x+2,y+2);
					put(x+1,y+2);
					put(x+2,y+1);
				}
			}
		}
	}
	if (n%4){
		for(int i=0;i+4<=n;i+=4){
			put(i+2,n);
			put(i+1,n);
			put(i+1,i+4);
			put(i+2,i+3);
			put(i+4,n);
			put(i+3,n);
			put(i+1,i+2);
			put(i+3,i+4);
			put(i+1,i+3);
			put(i+2,i+4);
		}
	}
	else{	
		for(int i=0;i+4<=n;i+=4){
			put(i+1,i+2);
			put(i+3,i+4);
			put(i+2,i+3);
			put(i+1,i+4);
			put(i+1,i+3);
			put(i+2,i+4);
		}
	}
	return 0;
}