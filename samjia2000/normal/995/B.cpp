#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 105;

int a[N*2];
int fi[N],se[N];
int n;

int main(){
	n=get();
	fo(i,1,n*2){
		a[i]=get();
		if (fi[a[i]])se[a[i]]=i;
		else fi[a[i]]=i;
	}
	int ans=0;
	fo(i,1,n)ans=ans+se[i]-fi[i]-1;
	fo(i,1,n)
		fo(j,1,n)
		if(fi[i]<fi[j]&&fi[j]<se[i]&&se[i]<se[j])ans--;
	cout<<ans<<endl;
	return 0;
}