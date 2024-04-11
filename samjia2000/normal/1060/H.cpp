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

const int N = 15;
const int L = 30;

LL c[N][N];
int d,mo;

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

LL a[N][N];
LL p[N][N];
int m;
int mi[L+5];
int tim[L+5];
int Mi[L+5];
bool vis[5005];

void clear(int x){
	fo(i,0,30)if (((1<<i)&(mo-1))>0)printf("+ %d %d %d\n",x,mi[i],x);
}

void add(int ret,int x,int tim){
	int A=++m;
	clear(A);
	printf("+ %d %d %d\n",x,A,A);
	for(;tim;tim/=2){
		if (tim&1)printf("+ %d %d %d\n",ret,A,ret);
		printf("+ %d %d %d\n",A,A,A);
	}
}

int getsquare(int w){
	Mi[1]=++m;
	printf("+ %d %d %d\n",w,5000,m);
	fo(i,2,d){
		Mi[i]=++m;
		printf("+ %d %d %d\n",Mi[i-1],5000,Mi[i]);
	}
	fo(i,1,d)printf("^ %d %d\n",Mi[i],Mi[i]);
	int ret=++m;
	clear(ret);
	fo(i,1,d)
	if (p[2][i])add(ret,Mi[i],p[2][i]);
	if (a[2][0])add(ret,5000,mo-a[2][0]);
	return ret;
}

int multi(int x,int v){
	int ret=++m;
	clear(ret);
	add(ret,x,v);
	return ret;
}

int main(){
	d=get();mo=get();
	c[0][0]=1;
	fo(i,1,d){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	fo(u,1,d){
		fo(i,0,d)a[u][i]=c[d][i]*quickmi(u,d-i,mo)%mo;
		p[u][u]=1;
	}
	fo(i,1,d){
		if (!a[i][i]){
			fo(j,i+1,d)
			if (a[j][i]){
				fo(x,0,d){
					swap(p[i][x],p[j][x]);
					swap(a[i][x],a[j][x]);
				}
				break;
			}
		}
		LL ny=quickmi(a[i][i],mo-2,mo);
		fo(x,0,d){
			a[i][x]=a[i][x]*ny%mo;
			p[i][x]=p[i][x]*ny%mo;
		}
		fo(j,1,d)
		if (a[j][i]&&j!=i){
			LL tmp=mo-a[j][i];
			fo(x,0,d){
				a[j][x]=(a[j][x]+a[i][x]*tmp)%mo;
				p[j][x]=(p[j][x]+p[i][x]*tmp)%mo;
			}
		}
	}
	m=3;
	mi[0]=3;
	fo(i,1,30){
		mi[i]=++m;
		printf("+ %d %d %d\n",mi[i-1],mi[i-1],mi[i]);
	}
	int px=getsquare(1);
	int py=getsquare(2);
	int w=++m;
	printf("+ %d %d %d\n",1,2,w);
	int pxy=getsquare(w);
	px=multi(px,mo-1);
	py=multi(py,mo-1);
	printf("+ %d %d %d\n",pxy,px,pxy);
	printf("+ %d %d %d\n",pxy,py,pxy);
	int target=multi(pxy,(mo+1)/2);
	printf("f %d\n",target);
	return 0;
}