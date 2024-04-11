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

const int N = 1e5+5;
const int L = 7e3+5;

typedef bitset<L> BIT;

int n,q;
int pri[7005],k,mu[7005];
BIT a[N];
BIT d[7005];
bool bz[7005];
BIT pv[7005];

void prepare(){
	mu[1]=1;
	fo(i,2,7000){
		if (!bz[i])mu[pri[++k]=i]=1;
		fo(j,1,k){
			if (i*pri[j]>7000)break;
			mu[i*pri[j]]=mu[i];
			bz[i*pri[j]]=1;
			if (i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
	fo(i,1,7000){
		int lim=sqrt(i);
		d[i].reset();
		fo(x,1,lim)
		if (i%x==0)d[i][x]=d[i][i/x]=1;
		fo(j,1,7000/i)if (mu[j])pv[i][i*j]=1;
	}
	fo(i,1,n)a[i].reset();
}

BIT tmp;

int main(){
	n=get();
	q=get();
	prepare();
	fo(i,1,q){
		int ty=get();
		if (ty==1){
			int x=get(),v=get();
			a[x]=d[v];
		//	printf("<%d>",i);fo(y,1,7000)if (a[x][y])printf("%d ",y);putchar('\n');
		}
		if (ty==2){
			int x=get(),y=get(),z=get();
			a[x]=a[y]^a[z];
		//	printf("<%d>",i);fo(y,1,7000)if (a[x][y])printf("%d ",y);putchar('\n');
		}
		if (ty==3){
			int x=get(),y=get(),z=get();
			a[x]=a[y]&a[z];
		//	printf("<%d>",i);fo(y,1,7000)if (a[x][y])printf("%d ",y);putchar('\n');
		}
		if (ty==4){
			int x=get(),v=get();
		//	printf("<%d>",i);fo(y,1,7000)if (a[x][y])printf("%d ",y);putchar('\n');
			tmp=a[x]&pv[v];
			int ret=tmp.count()&1;
			putchar('0'+ret);
		}
	}
	putchar('\n');
	return 0;
}