#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;

int n,q;
int a[N];
int f[N][20];
int nxt[20];

int main(){
	n=get();q=get();
	fo(i,1,n)a[i]=get();
	fd(i,n,1){
		fo(x,0,19)
		if ((a[i]&(1<<x))>0)f[i][x]=i;else f[i][x]=n+1;
		fo(x,0,19)
		if ((a[i]&(1<<x))>0){
			if (nxt[x]){
				fo(y,0,19)
				f[i][y]=min(f[i][y],f[nxt[x]][y]);
			}
			nxt[x]=i;
		}
	}
	fo(cas,1,q){
		int x=get(),y=get();
		bool ans=0;
		fo(w,0,19)
		if ((a[y]&(1<<w))>0)ans|=(f[x][w]<=y);
		if (ans)printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}