#include<cstdio>
#include<cstring>
using namespace std;
const int o=5e6+10;
int n,k,t[o],tot,z=o,sk;char s[o];bool flg[o],p[o];
int main(){
	scanf("%s",s+1);n=strlen(s+1);s[0]=s[n+1]='_';
	for(int i=0,j=0;i<n+3;++i)
		if(s[i]=='_') ++j;else{if(j) t[++tot]=j;j=0;}
	for(int i=1;i<=tot;flg[t[i++]]=1) if(z>t[i]) z=t[i];
	if(flg[z+1]) z-=2;
	if(z<1){printf("-1");return 0;}
	if(z==1) for(int i=2;i<n+3;++i) if(flg[i]){printf("-1");return 0;}
	if(z==2) for(int i=3;i<n+3;i+=2) if(flg[i]){printf("-1");return 0;}
	for(int i=0,j;i<n+2;)
		if(s[i]=='_'){
			for(j=i;s[j+1]=='_';++j);
			if((i+z-1)%2==j%2) for(int $=i;$+z-1<=j;$+=2) p[$]=1;
			else{p[i]=1;for(int $=i+3;$+z-1<=j;$+=2) p[$]=1;}
			i=j+1;
		}
		else ++i;
	for(int i=0;i<n+2;++i) if(p[i]) t[k++]=i;
	printf("%d\n",k-1);
	for(int i=1;i<k;++i) printf("%d ",t[i]-t[i-1]-1);
	return 0;
}