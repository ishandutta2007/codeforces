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

int k;
LL pa,pb,ny;
LL ga[N][N],gb[N][N],fb[N][N],fa[N][N];

LL quickmi(LL x,LL tim){LL ans=1;for(;tim;tim/=2,x=x*x%mo)if (tim&1)ans=ans*x%mo;return ans;}

int main(){
	k=get();pa=get();pb=get();
	ny=quickmi(pa+pb,mo-2);
	pa=pa*ny%mo,pb=pb*ny%mo;
	gb[0][0]=1;
	fo(i,0,k)
		fo(j,1,k){
			ga[i][j]=(ga[i][j-1]+gb[i][j-1])*pa%mo;
			if (i>=j)gb[i][j]=(ga[i-j][j]+gb[i-j][j])*pb%mo;
		}
	LL nya=quickmi((1ll+mo-pa)%mo,mo-2),ans=0;
	LL v=(nya-1)*nya%mo;
	fo(i,0,k-1)
		fo(j,0,k)
		if (gb[i][j]){
			int d=max(k-i,j)-j;
			int u=i+j+d;
			ans=(ans+gb[i][j]*(nya*u%mo+v)%mo*pb%mo*quickmi(pa,d)%mo)%mo;
		}
	ans=ans*quickmi((1ll+mo-pb)%mo,mo-2)%mo;
	cout<<ans<<endl;
	return 0;
}