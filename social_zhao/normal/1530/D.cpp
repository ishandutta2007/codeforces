#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<algorithm>
#include<queue>
using namespace std;

inline bool isdigit(char c) {return c>='0'&&c<='9';}

inline int read() {
	int res=0,f=1;char ch;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	do {
		res=res*10+ch-'0';
	} while(isdigit(ch=getchar()));
	return res*f;
}

const int N=1e6+5;

int T,n,a[N],ans[N],rev[N],b[N],tot;
int t[N],c;

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),tot=0;
		for(int i=1 ; i<=n ; ++i) scanf("%d",&a[i]),ans[i]=rev[i]=0;
		for(int i=1 ; i<=n ; ++i) if(!rev[a[i]]) ans[i]=a[i],rev[a[i]]=i;
		c=0;
		for(int i=1 ; i<=n ; ++i) if(!ans[i]) t[++c]=i;
		for(int i=1 ; i<=n ; ++i) if(!rev[i]) b[++tot]=i;
		if(tot==1&&!rev[t[c]]) {
			int pos=rev[a[t[c]]];
			ans[pos]=t[c],ans[t[c]]=a[t[c]],rev[a[t[c]]]=t[c];
		}
		else {
			for(int i=1 ; i<=c ; ++i) ans[t[i]]=b[c-i+1];
			for(int i=1 ; i<=c ; ++i)
				if(ans[t[i]]==t[i]) {
					if(i!=1) swap(ans[t[i]],ans[t[i-1]]);
					else swap(ans[t[i]],ans[t[i+1]]);
				}
		}
		int cnt=0;
		for(int i=1 ; i<=n ; ++i) cnt+=(ans[i]==a[i]);
		printf("%d\n",cnt);
		for(int i=1 ; i<=n ; ++i) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}