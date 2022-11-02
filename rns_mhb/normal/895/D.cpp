#include<bits/stdc++.h>
#define N 1000010
int g(int a,int m){int r,q,x=1,y=0;while(m)r=a%m,q=a/m,a=m,m=r,r=x,x=y,y=r-y*q;return x;}
int f[N],v[N],a[26],b[26],l,p=1e9+7;
int x(int a,int b){return int(1ll*a*b%p);}
int o(char*s,int*d,int m){int r=0,i,j,c;
    for(i=0;i<l;i++){c=s[i]-'a';
        for(j=0;j<c;j++)if(d[j])r=(r+x(f[l-i-1],x(m,d[j])))%p;
        if(!d[c])break;
        m=x(m,d[c]--);
    }return r;
}
char s[N],t[N];
main(){
    scanf("%s%s",&s,&t);l=strlen(s);int i,m=1;
    for(i=0,f[0]=1;i<l;i++)f[i+1]=x(f[i],i+1),a[s[i]-'a']++;
    for(i=l,v[l]=g(f[l],p);i;i--)v[i-1]= x(v[i],i);
    for(i=0;i<26;i++)b[i]=a[i],m=x(m,v[a[i]]);
    printf("%d",(o(t,a,m)-o(s,b,m)+p-1)%p);
}