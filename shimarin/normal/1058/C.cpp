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
int n,a[110],t,flag,s,sum;
inline int R(){
    char c;
    while(!isdigit(c=getchar()));
    return c-'0';
}
int main(){
    scanf("%d\n",&n);
    For(i,1,n) a[i]=R(),sum+=a[i];
    For(i,0,sum){
        t=flag=s=0;
        For(j,1,n){
            t+=a[j];
            if(t>i){flag=1;break;}
            if(t==i) t=0,++s;
        }
        if(!flag&&s>=2&&t==0) return printf("YES"),0;
    }
    printf("NO");
}