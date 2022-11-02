#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_L 40
#define p 1000000007

int t,f[max_L][2][2][2],g[max_L][2][2][2],pw2[max_L];

//a<or=n b<or=m c<or=k

inline int calc(int n,int m,int k){
	if(n<0||m<0)return 0;
	memset(f,0,sizeof f),memset(g,0,sizeof g);
	f[0][1][1][1]=1;
	for(int i=0,j;i<=30;++i){
		j=30-i;
		for(int a=0;a<2;++a)for(int b=0;b<2;++b)for(int c=0;c<2;++c){
			if(!f[i][a][b][c])continue;
			int tn=(n>>j)&1,tm=(m>>j)&1,tk=(k>>j)&1;
			for(int x=0;x<2;++x)if(!a||x<=tn)
				for(int y=0;y<2;++y)if(!b||y<=tm){
					int z=x^y;
					if(c&&z>tk)continue;
					int ta=a&&x==tn,tb=b&&y==tm,tc=c&&z==tk;
					f[i+1][ta][tb][tc]=(f[i+1][ta][tb][tc]+f[i][a][b][c])%p;
					g[i+1][ta][tb][tc]=(g[i+1][ta][tb][tc]+g[i][a][b][c])%p;
					if(z)g[i+1][ta][tb][tc]=(g[i+1][ta][tb][tc]+1ll*pw2[j]*f[i][a][b][c]%p)%p;
				}
		}
	}
	int ans=0;
	for(int a=0;a<2;++a)for(int b=0;b<2;++b)for(int c=0;c<2;++c){
		ans=(ans+g[31][a][b][c])%p;
		ans=(ans+f[31][a][b][c])%p;
	}
	return ans;
}

int main(){
	pw2[0]=1;
	for(int i=1;i<=30;++i)pw2[i]=(pw2[i-1]<<1)%p;
	for(t=gint();t--;){
		int x1,x2,y1,y2,k;
		x1=gint()-1,y1=gint()-1,x2=gint()-1,y2=gint()-1,k=gint()-1;
		int ans=(calc(x2,y2,k)+calc(x1-1,y1-1,k))%p;
		ans=(ans-(calc(x2,y1-1,k)+calc(x1-1,y2,k))%p)%p;
		printf("%d\n",(ans+p)%p);
	}
	return 0;
}