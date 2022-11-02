#include<cstdio>
#include<algorithm>

#define N 100010

using namespace std;

struct lhy{
    int x,y,id;
}p[N],L[N],R[N],U[N],D[N];

long long ans;
int n,k,x1,y1,x2,y2,Time,flag[N];

inline int cmp1(const lhy &a,const lhy &b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

inline int cmp2(const lhy &a,const lhy &b)
{
    if(a.x!=b.x)return a.x>b.x;
    return a.y<b.y;
}

inline int cmp3(const lhy &a,const lhy &b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}

inline int cmp4(const lhy &a,const lhy &b)
{
    if(a.y!=b.y)return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        p[i]=(lhy){x1+x2,y1+y2,0};
        L[i]=R[i]=U[i]=D[i]=p[i];
        L[i].id=R[i].id=U[i].id=D[i].id=i;
    }
    ans=1000000000000000000ll;
    sort(L+1,L+1+n,cmp1);
    sort(R+1,R+1+n,cmp2);
    sort(U+1,U+1+n,cmp3);
    sort(D+1,D+1+n,cmp4);
    for(int l=0;l<=k;l++)
        for(int r=0;r<=k;r++)
            for(int d=0;d<=k;d++)
            {
                int cnt=0;
                Time++;
                for(int i=1;i<=l;i++)
                    flag[L[i].id]=Time,cnt++;
                for(int i=1;i<=r;i++)
                    if(flag[R[i].id]!=Time)flag[R[i].id]=Time,cnt++;
                for(int i=1;i<=d;i++)
                    if(flag[D[i].id]!=Time)flag[D[i].id]=Time,cnt++;
                if(cnt>k)continue;
                for(int i=1;i<=n&&cnt<k;i++)
                    if(flag[U[i].id]!=Time)flag[U[i].id]=Time,cnt++;
                int Maxx=0,Maxy=0,Minx=2000000001,Miny=2000000001;
                for(int i=1;i<=n;i++)
                    if(flag[i]!=Time)
                    {
                        Maxx=max(Maxx,p[i].x);
                        Minx=min(Minx,p[i].x);
                        Maxy=max(Maxy,p[i].y);
                        Miny=min(Miny,p[i].y);
                    }
                int X=Maxx-Minx,Y=Maxy-Miny;
                if(X%2==1)X++;
                if(Y%2==1)Y++;
                X=max(X,2);
                Y=max(Y,2);
                ans=min(ans,1ll*X*Y/4);
            }
    printf("%I64d\n",ans);
}