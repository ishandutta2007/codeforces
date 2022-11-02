#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define clr(u) memset(u,0,sizeof(u))
#define N 20
#define M 1<<18
__int64 f[M][100];bool use[N];

int main(){
    //freopen("in.txt","r",stdin);

    int i,j,t,k,len,r,b[N],d[N],a[N],m;char s[N];

    b[0]=1;
	for(i=1;i<N;i++) b[i]=b[i-1]*2;

    scanf("%s %d",s,&m);

    len=strlen(s);
    for(i=0;i<len;i++) a[i]=s[i]-'0';
    sort(a,a+len);

    f[0][0]=1;
    for(i=1;i<b[len];i++){
        r=i;k=0;clr(use);
		while(r>0){
			if(r%2){
				if(!use[a[k]]){
					use[a[k]]=1;
					for(j=0;j<m;j++) if(a[k]||(i-b[k])) f[i][(j*10+a[k])%m]+=f[i-b[k]][j];
				}
			}
			k++;r/=2;
		}
    }

    printf("%I64d\n",f[b[len]-1][0]);
    return 0;
}