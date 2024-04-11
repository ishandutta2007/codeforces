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

const int N = 10005;

int n;
LL a[N];
int X,d;

int main(){
	X=get(),d=get();
	fd(i,30,1){
		while (X>=((1<<i)-1)){
			X=X-((1<<i)-1);
			if (!n){
				fo(x,1,i)a[++n]=1;
			}
			else{
				LL v=a[n]+d;
				fo(x,1,i)a[++n]=v;
			}
		}
	}
	printf("%d\n",n);
	fo(i,1,n)cout<<a[i]<<" ";
	return 0;
}