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

const int N = 1e5+5;

int n;
int key[N*2];
int u;

int main(){
	n=get();
	LL ans=0;
	fo(i,1,n){
		int a1=get(),b1=get(),a2=get(),b2=get();
		if (a1+b1>=a2+b2){
			key[++u]=a1+b1;
			key[++u]=a2+b2;
			ans=ans+a1+a2;
		}
		else{
			if (a1>b2)ans=ans+a1-b2;
			if (b1>a2)ans=ans+a2-b1;
		}
	}
	sort(key+1,key+1+u);
	for(int i=1;i<=u;i+=2)ans=ans-key[i];
	cout<<ans<<endl;
	return 0;
}