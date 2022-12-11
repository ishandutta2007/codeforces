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

const int N = 3005;

int n,m;
int p[N],c[N],tp[N],tc[N];
int num[N];
int ta[N],lst[N];

bool cmp(int x,int y){return c[x]<c[y];}

bool bz[N];
int all[N];

int main(){
	n=get();m=get();
	int cnt=0;
	fo(i,1,n){
		tp[i]=p[i]=get(),tc[i]=c[i]=get();
		num[i]=i;
		if (p[i]==1)cnt++;
		all[p[i]]++;
	}
	sort(num+1,num+1+n,cmp);
	fo(i,1,n)p[i]=tp[num[i]],c[i]=tc[num[i]];
	fd(i,n,1){
		lst[i]=ta[p[i]];
		ta[p[i]]=i;
	}
	LL ans=1e18;
	fo(l,1,n){
		fo(i,1,n)bz[i]=0;
		LL cst=0;
		int pcnt=cnt;
		fo(i,2,m)
		if (all[i]>=l){
			for(int tim=1,now=ta[i];tim<=all[i]-l+1;now=lst[now],tim++){
				bz[now]=1;
				cst=cst+c[now];
			}
			cnt+=all[i]-l+1;
		}
		int res=max(0,l-cnt);
		fo(i,1,n)
		if (!bz[i]&&res&&p[i]!=1){
			res--;
			cst=cst+c[i];
		}
		if (!res&&cst<ans)ans=cst;
		cnt=pcnt;
	}
	cout<<ans<<endl;
	return 0;
}