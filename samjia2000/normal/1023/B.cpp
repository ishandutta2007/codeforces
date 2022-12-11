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
	LL n,k;
	cin>>n>>k;
	if (k<=2){
		printf("0\n");
		return 0;
	}
	LL lim=k/2;
	if (k%2==0)lim--;
	LL low=k-n;
	if (low<1)low=1;
	if (low<=lim)cout<<lim-low+1<<endl;
	else cout<<0<<endl;
	return 0;
}