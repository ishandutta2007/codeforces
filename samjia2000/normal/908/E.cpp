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

const int N = 1005;
const int mo = 1e9+7;

LL val[N];
int n,m;
char s[N];
LL f[N][N],c[N];

int main(){
	m=get();n=get();
	fo(i,1,n){
		scanf("%s",s+1);
		fo(j,1,m)val[j]=val[j]<<1|(s[j]=='1');
	}
	f[1][1]=c[1]=1;
	fo(i,2,m){
		fo(j,1,i){
			f[i][j]=(f[i-1][j]*j+f[i-1][j-1])%mo;
			c[i]=(c[i]+f[i][j])%mo;
		}
	}
	sort(val+1,val+1+m);
	int lst=0;
	LL ans=1;
	fo(i,1,m){
		if (i==m||val[i]!=val[i+1]){
			ans=ans*c[i-lst]%mo;
			lst=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}