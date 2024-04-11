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

int n,m;
int p[100005],q[100005];

int main(){
	int a=get(),b=get();
	fd(ans,100000,0){
		if (1ll*ans*(ans+1)/2<=a+b){
			n=m=0;
			if (a<b){
				if (a>1ll*ans*(ans+1)/2)a=1ll*ans*(ans+1)/2;
				fd(i,ans,1){
					if (a<=1ll*i*(i-1)/2)q[++m]=i;
					else{
						p[++n]=i;
						a-=i;
					}
				}
				printf("%d\n",n);
				fo(i,1,n)printf("%d ",p[i]);
				putchar('\n');
				printf("%d\n",m);
				fo(i,1,m)printf("%d ",q[i]);
				putchar('\n');
				return 0;
			}
			else{
				if (b>1ll*ans*(ans+1)/2)b=1ll*ans*(ans+1)/2;
				fd(i,ans,1){
					if (b<=1ll*i*(i-1)/2)p[++n]=i;
					else{
						q[++m]=i;
						b-=i;
					}
				}
				printf("%d\n",n);
				fo(i,1,n)printf("%d ",p[i]);
				putchar('\n');
				printf("%d\n",m);
				fo(i,1,m)printf("%d ",q[i]);
				putchar('\n');
				return 0;
				
			}
		}
	}
	return 0;
}