#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=2e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;

string s1="What are you doing at the end of the world? Are you busy? Will you save us?";
string s2="What are you doing while sending ";
string s3="? Are you busy? Will you send ";
string s4="?";
int q,n,m;
int len1,len2,len3,len4;
int len[N];
char get(int a,int b)
{
    //
//    printf("get(%lld,%lld)\n",a,b);
    if (len[a]<=b) return '.';
    if (a==0) 
    {
        return s1[b];
    }
    if (b<len2) return s2[b];
    b-=len2;
    if (len[a-1]>b)
    {
        return get(a-1,b); 
    }
    b-=len[a-1];
    if (b<len3) return s3[b];
    b-=len3;
    if (len[a-1]>b)
    {
        return get(a-1,b);
    }
    b-=len[a-1];
    return s4[b];
}
signed main()
{
    s2=s2+'"';
    s3='"'+s3+'"';
    s4='"'+s4;
    len1=s1.length();
    len2=s2.length();
    len3=s3.length();
    len4=s4.length();
    rd(q);
    len[0]=len1;
    for (int i=1;i<N;i++)
    {
        if (len[i-1]>(1e18)) len[i]=inf;else
        len[i]=len2+len[i-1]+len3+len[i-1]+len4;
    }
    while (q--)
    {
        rd(n);rd(m);
        m--;
        //f(n)m
        //f(n)
        cout<<get(n,m);
    }
}