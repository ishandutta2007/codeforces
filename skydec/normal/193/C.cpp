#include<stdio.h>
#include<cstring>
#define MAXN 1010000
using namespace std;
long max(long a,long b){if(a>b)return a;return b;}
long s12,s13,s14,s23,s24,s34;
bool temp1[MAXN];
bool temp2[MAXN];
bool temp3[MAXN];
bool temp4[MAXN];
char str[3];
bool check(long len,bool put)
{
     for(long i=1;i<=len;i++)temp1[i]=1;
     for(long j=1;j<=s12;j++)temp2[j]=0;
     for(long j=s12+1;j<=len;j++)temp2[j]=1;
     long p=(s23+s13-s12)/2;
     if(p<0||p>len-s12)return false;
     long s=s13-p;
     if(s<0||s>s12)return false;
     for(long j=len-p+1;j<=len;j++)temp3[j]=0;
     for(long j=s12+1;j<=len-p;j++)temp3[j]=1;
     for(long j=1;j<=s;j++)temp3[j]=0;
     for(long j=s+1;j<=s12;j++)temp3[j]=1;
     long l1,l2,l3,l4;
     l2=s;
     l1=s12-l2;
     l3=(len-s12)-p;
     l4=(len-l1-l2-l3);
     if(l1<0||l2<0||l3<0||l4<0)return false;
     if((s24+s34-len+l1-len+l4)%2!=0)return false;
     if((s14+s24-len+l2-len+l1)%2!=0)return false;
     if((s14+s34-len+l2-len+l4)%2!=0)return false;
     long x1,x2,x3,x4;
     for(x1=0;x1<=(s14+s34-len+l2-len+l4)/(-2);x1++)
     {
       x3=((s14+s34-len+l2-len+l4)/(-2))-x1;
       x4=((s14+s24-len+l2-len+l1)/(-2))-x3;
       x2=((s24+s34-len+l1-len+l4)/(-2))-x3;
       if(x2<0||x3<0||x4<0)continue;
       if(x2>l2)continue;
       if(x3>l3)continue;
       if(x4>l4)continue;
       if(x1>l1)continue;
       if(!put)return true;
       for(long i=1;i<=x2;i++)temp4[i]=0;
       for(long i=x2+1;i<=l2;i++)temp4[i]=1;
       for(long i=l2+1;i<=l2+x1;i++)temp4[i]=1;
       for(long i=l2+x1+1;i<=l2+l1;i++)temp4[i]=0;
       for(long i=l2+l1+1;i<=l2+l1+x3;i++)temp4[i]=1;
       for(long i=l2+l1+x3+1;i<=l2+l1+l3;i++)temp4[i]=0;
       for(long i=l2+l1+l3+1;i<=l2+l1+l3+x4;i++)temp4[i]=1;
       for(long i=l2+l1+l3+x4+1;i<=len;i++)temp4[i]=0;
       for(long i=1;i<=len;i++)printf("%c",str[temp1[i]]);printf("\n");
       for(long i=1;i<=len;i++)printf("%c",str[temp2[i]]);printf("\n");
       for(long i=1;i<=len;i++)printf("%c",str[temp3[i]]);printf("\n");
       for(long i=1;i<=len;i++)printf("%c",str[temp4[i]]);printf("\n");
       break;
       }
     return false;
}
int main()
{
    scanf("%ld%ld%ld%ld%ld%ld",&s12,&s13,&s14,&s23,&s24,&s34);
    long l,r;long ans=0;l=0;
    l=max(l,s12);
    l=max(l,s23);
    l=max(l,s24);
    l=max(l,s34);
    l=max(l,s13);
    l=max(l,s14);
    str[0]='a';
    str[1]='b';
    r=l*10;
    while(l<r)
    {
              long mid=(l+r)>>1;
              if(check(mid,0))
              {
                            ans=mid;
                            r=mid;
                            }
              else l=mid+1;
              }
    if(check(l,0))ans=l;
    if(!ans)printf("-1");
    else{
    printf("%ld\n",ans);
    check(ans,1);}
    return 0;
}