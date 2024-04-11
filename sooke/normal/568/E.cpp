#include<bits/stdc++.h>
#define r(x) scanf("%d",&x)
#define o(x,y) f[k]=x,g[k]=y,h[k]=std::max(g[k-1],h[k-1])
const int N=1e6;
int n,m,a[N],b[N],f[N],g[N],h[N],l[N],u[N];
int main(){
    r(n);for(int i=0;i<n;i++)r(a[i]);a[n]=11e8;
    r(m);for(int i=0;i<m;i++)r(b[i]);std::sort(b,b+m);
    memset(f+1,99,n*4);g[0]=h[0]=-1;
    for(int i=0,k=n;i<=n;i++,k=n)
        if(~a[i])k=std::lower_bound(f,f+n+1,a[i])-f,o(a[i],i),l[i]=h[k];
        else for(int j=m-1;~j;j--){
            while(f[k-1]>=b[j])k--;o(b[j],-2);
        }
    for(int i=n,j=n,k=m-1;~i;i--){
        if(i==j)j=l[i];
        else if(b[k]>a[j]&&!~a[i])a[i]=b[k],u[k]=1;
        else continue;
        while(b[k]>=a[i])k--;
    }
    for(int i=0,k=0;i<n;i++){
        while(u[k])k++;
        printf("%d ",~a[i]?a[i]:b[k++]);
    }
}