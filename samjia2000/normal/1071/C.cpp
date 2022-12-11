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
const int L = (1<<8)+5;

int n;
int a[N];
int f[L];
int que[L];
int lst[L];
struct operation{
	int x,y,z;
	operation(const int x_=0,const int y_=0,const int z_=0){x=x_;y=y_;z=z_;}
}op[N];
int tmp[N];

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	int l=min(n,8);
	fo(i,0,(1<<l)-1)f[i]=-1;
	f[0]=0;
	int he=0,ta=1;
	que[1]=0;
	while(he<ta){
		int u=que[++he];
		fo(x,0,l-1)
			fo(y,x+1,l-1){
				int z=y+(y-x);
				if (z<l){
					int v=u^(1<<x)^(1<<y)^(1<<z);
					if (f[v]==-1){
						f[v]=f[u]+1;
						que[++ta]=v;
						lst[v]=u;
					}
				}
			}
	}
	if (n<8){
		int u=0;
		fo(i,1,n)if (a[i])u|=(1<<(i-1));
		int m=0;
		if (f[u]==-1||f[u]>(n/3)+12)printf("NO\n");
		else{
			for(int now=u;now;now=lst[now]){
				int v=now^lst[now];
				m++;
				fo(i,0,n-1)
				if (((1<<i)&v)>0){
					if (!op[m].x)op[m].x=i+1;
					else{
						if (!op[m].y)op[m].y=i+1;
						else op[m].z=i+1;
					}
				}
			}
				printf("YES\n%d\n",m);
				fo(i,1,m)printf("%d %d %d\n",op[i].x,op[i].y,op[i].z);
		}
		return 0;
	}
	int m=0;
	for(int st=1;n-st>=8;st+=3){
		int cnt=a[st]+a[st+1]+a[st+2];
		if (n-(st+1)<8)cnt-=a[st+1];
		if (n-(st+2)<8)cnt-=a[st+2];
		if (cnt==0)continue;
		if (cnt==3){
			a[st]^=1,a[st+1]^=1,a[st+2]^=1;
			op[++m]=operation(st,st+1,st+2);
		}
		if (cnt==1){
			int x=0;
			fo(i,st,st+2)if (a[i]){x=i;break;}
			if (n-x>=8){
				a[x]^=1,a[x+3]^=1,a[x+6]^=1;
				op[++m]=operation(x,x+3,x+6);
			}
		}
		if (cnt==2){
			bool can=0;
			fo(x1,st,st+5){
				fo(d1,1,5){
					fo(x2,st,st+5){
						fo(d2,1,5){
							fo(i,st,st+5)tmp[i]=a[i];
							if (x1+d1+d1<=n&&x2+d2+d2<=n){
								tmp[x1]^=1,tmp[x1+d1]^=1,tmp[x1+d1+d1]^=1;
								tmp[x2]^=1,tmp[x2+d2]^=1,tmp[x2+d2+d2]^=1;
								can=1;
								fo(i,st,st+5)if (n-i>=8&&tmp[i]){can=0;break;}
								if (can){
									op[++m]=operation(x1,x1+d1,x1+d1+d1);
									op[++m]=operation(x2,x2+d2,x2+d2+d2);
									a[x1]^=1,a[x1+d1]^=1,a[x1+d1+d1]^=1;
									a[x2]^=1,a[x2+d2]^=1,a[x2+d2+d2]^=1;
								}
							}
							if (can)break;
						}
						if(can)break;
					}
					if (can)break;
				}
				if (can)break;
			}
		}
	}
	int u=0;
	fd(i,n,n-7)if (a[i])u|=(1<<(n-i));
	for(int now=u;now;now=lst[now]){
		int v=now^lst[now];
		m++;
		fo(i,0,7)
		if (((1<<i)&v)>0){
			if (!op[m].z)op[m].z=n-i;
			else{
				if (!op[m].y)op[m].y=n-i;
				else op[m].x=n-i;
			}
		}
	}
	printf("YES\n%d\n",m);
	fo(i,1,m)printf("%d %d %d\n",op[i].x,op[i].y,op[i].z);
	return 0;
}