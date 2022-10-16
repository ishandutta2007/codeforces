
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int T;
struct seg
{
    int x[3],y[3];
    void get()
    {
        rd(x[1]);rd(y[1]);rd(x[2]);rd(y[2]);
    }
    void put()
    {
        printf("%lld %lld %lld %lld\n",x[1],y[1],x[2],y[2]);
    }
}S[4];
bool onseg(seg s1,int x,int y)
{
    if ((x-s1.x[1])*(x-s1.x[2])>0) return 0;
    if ((y-s1.y[1])*(y-s1.y[2])>0) return 0;
    if ((x-s1.x[1])*(y-s1.y[2])!=(x-s1.x[2])*(y-s1.y[1])) return 0;
    int dx1=abs(x-s1.x[1]),dx2=abs(x-s1.x[2]);
    int dy1=abs(y-s1.y[1]),dy2=abs(y-s1.y[2]);
    if (max(dx1,dx2)<=min(dx1,dx2)*4 && max(dy1,dy2)<=min(dy1,dy2)*4) return 1;
    return 0;
}
bool leq90(int X1,int Y1,int X2,int Y2)
{
    int aaa=X1*X2+Y1*Y2;
    int bbb=(X1*X1+Y1*Y1)*(X2*X2+Y2*Y2);
    if (aaa<0) return 0;//
    if (aaa==0) return 1;//
    if (aaa*aaa==bbb) return 0;//0
    return 1;//
}
bool chk(seg s1,seg s2,seg s3)
{
    //
    //    s1.1s2.1.
    //    s3.1s1,s3.2s2
    if (s1.x[1]==s2.x[1] && s1.y[1]==s2.y[1])
    {
        if (onseg(s1,s3.x[1],s3.y[1])) 
        {
            if (onseg(s2,s3.x[2],s3.y[2]))
            {
                int XX=s1.x[2]-s1.x[1];
                int YY=s1.y[2]-s1.y[1];
                int XXX=s2.x[2]-s2.x[1];
                int YYY=s2.y[2]-s2.y[1];
                if (leq90(XX,YY,XXX,YYY)) return 1;
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}
seg A(seg s1) {return s1;}
seg B(seg s1) {swap(s1.x[1],s1.x[2]);swap(s1.y[1],s1.y[2]);return s1;
}
bool check(seg s1,seg s2,seg s3)
{
    bool flag=0;
    flag|=chk(A(s1),A(s2),A(s3));
    flag|=chk(A(s1),A(s2),B(s3));
    flag|=chk(A(s1),B(s2),A(s3));
    flag|=chk(A(s1),B(s2),B(s3));
    flag|=chk(B(s1),A(s2),A(s3));
    flag|=chk(B(s1),A(s2),B(s3));
    flag|=chk(B(s1),B(s2),A(s3));
    flag|=chk(B(s1),B(s2),B(s3));
    return flag;
}
signed main()
{
    rd(T);
    while (T--)
    {
        bool flag=0;
        S[1].get();
        S[2].get();
        S[3].get();
        flag|=check(S[1],S[2],S[3]);
        flag|=check(S[1],S[3],S[2]);
        flag|=check(S[2],S[1],S[3]);
        flag|=check(S[2],S[3],S[1]);
        flag|=check(S[3],S[1],S[2]);
        flag|=check(S[3],S[2],S[1]);
        if (flag) puts("YES");
        else puts("NO");
    }
}