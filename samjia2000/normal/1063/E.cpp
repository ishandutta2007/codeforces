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

const int N = 1005;

int n;
int a[N];
bool vis[N];
int k,b[N];
char ans[N][N];

void arrange(int c,int x,int y){
	if (x<y)ans[c][x]=ans[c][y]='/';
	else ans[c][x]=ans[c][y]='\\';
}

int k1,b1[N];

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	bool pd=1;
	fo(i,1,n)pd&=(a[i]==i);
	if (pd){
		printf("%d\n",n);
		fo(i,1,n){
			fo(j,1,n)putchar('.');
			putchar('\n');
		}
	}
	else{
		int w=n,key=0;
		fo(i,1,n)fo(j,1,n)ans[i][j]='.';
		fo(i,1,n)
		if (!vis[i]){
			if (i==a[i])continue;
			k=0;
			for(int x=i;!vis[x];x=a[x])vis[b[++k]=x]=1;
			if (!key){
				k1=k;
				fo(x,1,k)b1[x]=b[x];
				key=i;
			}
			else{
				int st=w;
				ans[st][key]='\\';
				fd(x,k,2){
					arrange(w,b[x],b[x%k+1]);
					w--;
				}
				arrange(w,key,a[i]);
				w--;
			}
		}
		fd(x,k1,2){
			arrange(w,b1[x],b1[x%k1+1]);
			w--;
		}
		printf("%d\n",n-1);
		fo(i,1,n){
			fo(j,1,n)putchar(ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}