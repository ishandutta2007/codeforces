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
#define se second
#define fi first

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

const int N = 2001;

int n,a[N],b[N];

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	int pre=0;
	int ans=1e+9;
	fo(i,1,n){
		fo(j,1,n)b[j]=a[j];
		int cnt=0;
		fo(j,i,n){
			if (j>i)b[j]=gcd(b[j],b[j-1]);
			if (b[j]==1){
				int ct=0;
				fo(x,1,n)
				if (b[x]!=1)ct++;
				ans=min(ans,ct+cnt);
				break;
			}
			cnt++;
		}
	}
	if (ans==1e+9)ans=-1;
	printf("%d\n",ans);
	return 0;
}