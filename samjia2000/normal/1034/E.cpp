#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef unsigned long long ull;
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

const int L = (1<<21)+5;

int n,len;
ull a[L],b[L];
char s[L];

int main(){
	n=get();
	len=1<<n;
	scanf("%s",s);
	fo(i,0,len-1)a[i]=s[i]-'0';
	scanf("%s",s);
	fo(i,0,len-1)b[i]=s[i]-'0';
	fo(i,0,len-1){
		fo(x,0,n-1)
		if (((1<<x)&i)>0){
			a[i]=a[i]<<2;
			b[i]=b[i]<<2;
		}
	}
	for(int i=1;i<len;i<<=1)
		for(int j=0;j<len;j+=(i<<1))
			for(int k=0;k<i;k++){
				a[i+j+k]+=a[j+k];
				b[i+j+k]+=b[j+k];
			}
	fo(i,0,len-1)a[i]=a[i]*b[i];
	for(int i=1;i<len;i<<=1)
		for(int j=0;j<len;j+=(i<<1))
			for(int k=0;k<i;k++)a[i+j+k]-=a[j+k];
	fo(i,0,len-1){
		fo(x,0,n-1)
		if ((i&(1<<x))>0){
			a[i]=a[i]>>2;
		}
		putchar('0'+(a[i]&3));
	}
	putchar('\n');
	return 0;
}