#include<bits/stdc++.h>

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

const int N = 505;
const LL INF = 1e18;

int n;
struct element{
	LL a,b,k;
}a[N];

bool cmp(element a,element b){return a.b>b.b;}

LL f[N][N];

int main(){
	n=get();
	fo(i,1,n){
		a[i].a=get();a[i].b=get();a[i].k=get();
	}
	sort(a+1,a+1+n,cmp);
	fo(i,0,n)fo(j,0,n)f[i][j]=-INF;
	f[0][0]=0;
	fo(i,0,n-1)
		fo(j,0,n)
		if (f[i][j]>-INF){
			LL v=(LL)a[i+1].a-a[i+1].b*a[i+1].k;
			if (v<0)v=0;
			f[i+1][j]=max(f[i+1][j],f[i][j]+v);
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+a[i+1].a-1ll*a[i+1].b*j);
		}
	LL ans=0;
	fo(i,0,n)ans=max(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}