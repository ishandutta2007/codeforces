#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
inline int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int Div(int a,int b)
{
    if(a==0)return 0;
    if(a>0)return (a-1)/b+1;
    return a/b;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int x=read(),y=read(),p=read(),q=read();
        if(x*q==y*p)puts("0");
        //else if(x*q>y*p)puts("-1");
        else if(q==p)puts("-1");
        else if(p==0)puts("-1");
        else
        {
            //int L=(y*p-x*q-1)/(q-p)+1;
            int L=Div(y*p-x*q,q-p);
            int minb=q-y;
            minb%=q;minb+=q;minb%=q;
            //int _ZMF_=(x*q-y*p-1)/p+1;
            int _ZMF_=Div(x*q-y*p,p);
            L=L<_ZMF_?_ZMF_:L;
            if(minb>=L){printf("%lld\n",minb);continue;}
            int R=L-minb;
            R=Div(R,q);
            R*=q;
            minb+=R;
            printf("%lld\n",minb);
            //b+y%q
            /*{
                int d=1;
                int m=q/d,n=p/d;
                int mina=n-x;
                mina%=n;mina+=n;mina%=n;
                int aisge=(y*p-x*q-1)/(q-p)+1;
                int dela=aisge-mina;
                int qqq=(dela-1)/n+1;
                mina+=qqq*n;
                printf("%lld\n",(x+mina)*m/n-y);
                int d=gcd(q,p);
                int l=q/d;
                int j=(x-1)/l+1-x;
                printf("%lld\n",j*l*q/p-y);
            }*/
            
        }
        
    }
}