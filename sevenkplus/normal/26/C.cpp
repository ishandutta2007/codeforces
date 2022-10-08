#include<cstdio>
#include<algorithm>
int n,m,a,b,c;char s[111][111];
inline void e(){puts("IMPOSSIBLE");std::exit(0);}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    if(n%2&&m%2)e();
    if(n%2)a-=m/2;if(m%2)b-=n/2;
    if(a<0||b<0)e();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            s[i][j]=(i/2%2==j/2%2)?'a':'b';
    c-=(n/2)*(m/2);
    for(int i=0;i<n-n%2;i+=2)
        for(int j=0;j<m-m%2;j+=2)if(c<0)
        {
            if(a>1)a-=2,c++,s[i][j]=s[i][j+1]+=2;else
            if(b>1)b-=2,c++,s[i][j]=s[i+1][j]+=2;else e();
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            printf("%c%s",s[i][j],j==m-1?"\n":"");
    return 0;
}