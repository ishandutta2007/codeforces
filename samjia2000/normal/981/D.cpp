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

const int N = 55;

int n,k;
LL a[N];
bool f[N][N];

int main(){
	n=get(),k=get();
	fo(i,1,n)scanf("%I64d",&a[i]);
	fo(i,1,n)a[i]=a[i]+a[i-1];
	LL ans=0;
	fd(w,60,0){
		ans=ans^(1ll<<w);
		fo(i,0,n)fo(j,0,n)f[i][j]=0;
		f[0][0]=1;
		fo(i,1,n)
			fo(j,1,i)
				fo(x,0,i-1)
				if (((a[i]-a[x])&ans)==ans)f[i][j]=f[i][j]|f[x][j-1];
		if(!f[n][k]){
			ans=ans^(1ll<<w);
		}
	}
	cout<<ans<<endl;
	return 0;
}