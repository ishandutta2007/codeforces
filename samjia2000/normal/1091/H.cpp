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

const int N = 2e5+5;

typedef bitset<N> BIT;

int sg[N];
int f;
int pri[N],lst[N],k;
bool bz[N];
int n;
int key[N],m;
BIT tr,now,all;

int main(){
	n=get();f=get();
	fo(i,2,2e5){
		if (!bz[i]){
			pri[++k]=key[++m]=i;
			if (i==f)m--;
		}
		else if (!bz[lst[i]]&&i!=f)key[++m]=i;
		fo(j,1,k){
			if (i*pri[j]>2e5)break;
			lst[i*pri[j]]=i;
			bz[i*pri[j]]=1;
			if (i%pri[j]==0)break;
		}
	}
	int res=2e5+1;
	tr.reset();
	fo(i,1,m)tr[key[i]]=1;
	tr[f]=0;
	fo(i,0,2e5)sg[i]=-1;
	for(int v=0;res>0;v++){
		now.reset();
		fo(i,0,2e5)
		if (sg[i]==-1&&!now[i]){
			sg[i]=v;
			res--;
			now=now|(tr<<i);
		}
	}
	int g=0;
	fo(i,1,n){
		int x=get(),y=get(),z=get();
		z-=y;y-=x;
		z--,y--;
		g^=sg[z]^sg[y];
	}
	if (g)printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	return 0;
}