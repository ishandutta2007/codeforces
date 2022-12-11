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

const int N = 2e+5+5;

int n,m,k;
int rk[N];
struct edge{
	int x,nxt;
}e1[N],e2[N];
int h1[N],h2[N],tot1,tot2;
bool bz[N];
int Rig[N],Lef[N];
int que[N],r[N];

void inse1(int x,int y){e1[++tot1].x=y;e1[tot1].nxt=h1[x];h1[x]=tot1;}

void inse2(int x,int y){e2[++tot2].x=y;e2[tot2].nxt=h2[x];h2[x]=tot2;}

bool cmp(int x,int y){return Rig[x]>Rig[y];}

int main(){
	n=get();m=get();k=get();
	fo(i,1,n)bz[rk[i]=get()]=1;
	fo(i,1,m){
		int x=get(),y=get();
		inse1(x,y);
		inse2(y,x);
		r[y]++;
	}
	int he=0,ta=0;
	fo(i,1,n)Rig[i]=k;
	fo(i,1,n)
	if (!r[i])que[++ta]=i;
	for(;he<ta;){
		int x=que[++he];
		if (rk[x])Rig[x]=min(Rig[x],rk[x]);
		for(int p=h1[x];p;p=e1[p].nxt){
			r[e1[p].x]--;
			Rig[e1[p].x]=min(Rig[e1[p].x],Rig[x]-1);
			if (!r[e1[p].x])que[++ta]=e1[p].x;
		}
	}
	if (ta!=n)return printf("-1\n"),0;
	sort(que+1,que+1+n,cmp);
	set<int>s;
	s.clear();
	fo(i,1,k)
	if (!bz[i])s.insert(i);
	fd(i,n,1){
		int x=que[i];
		if (!rk[x]){
			set<int>::iterator h=s.lower_bound(Lef[x]);
			if((h!=s.end())&&(*h)<=Rig[x]){
				bz[rk[x]=(*h)]=1;
				s.erase(h);
			}
			else rk[x]=max(1,Lef[x]);
		}
		if (rk[x]<Lef[x])return printf("-1\n"),0;
		if (rk[x]>Rig[x])return printf("-1\n"),0;
		for(int p=h2[x];p;p=e2[p].nxt)
			Lef[e2[p].x]=max(Lef[e2[p].x],rk[x]+1);
	}
	fo(i,1,k)
	if (!bz[i])return printf("-1\n"),0;
	fo(i,1,n)printf("%d ",rk[i]);
	return 0;
}