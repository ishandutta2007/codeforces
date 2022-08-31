#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int T;
char c[1010];
int main(){
	T=read();
	while (T--){
		scanf("%s",c+1);int n=strlen(c+1),flag=1;
		sort(c+1,c+1+n);
		For(i,2,n) if (c[i]!=c[i-1]) flag=0;
		if (flag) puts("-1");
			else printf("%s\n",c+1);
	}
}