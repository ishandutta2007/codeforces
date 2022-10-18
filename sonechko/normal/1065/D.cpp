#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 10 + 11;

int dp1[N][N][N*N][5],dp2[N][N][N*N][5],num[N][N][N*N][5];
int xp[N*N],yp[N*N];
int a[N][N];
int kol,xx[N*N*N*N*N],yy[N*N*N*N*N],last[N*N*N*N*N],tt[N*N*N*N*N];
set<pair<int,pair<int,int> > > st;

void up(int l, int r, int la, int t, int ans, int gg)
{
    if (dp1[l][r][la][t]==0)
    {
        kol++;
        num[l][r][la][t]=kol;
        xx[kol]=l;
        yy[kol]=r;
        last[kol]=la;
        tt[kol]=t;
        dp1[l][r][la][t]=1e9;
    }
    if (dp1[l][r][la][t]<ans) return;
    if (dp1[l][r][la][t]==ans&&dp2[l][r][la][t]<=gg) return;
    st.erase(mp(dp1[l][r][la][t],mp(dp2[l][r][la][t],num[l][r][la][t])));
    dp1[l][r][la][t]=ans;
    dp2[l][r][la][t]=gg;
    st.insert(mp(dp1[l][r][la][t],mp(dp2[l][r][la][t],num[l][r][la][t])));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>a[i][j];
        xp[a[i][j]]=i;
        yp[a[i][j]]=j;
    }
    up(xp[1],yp[1],1,1,1,0);
    up(xp[1],yp[1],1,2,1,0);
    up(xp[1],yp[1],1,3,1,0);
    while (st.size()>0)
    {
        pair<int,pair<int,int> > p=*st.begin();
        st.erase(p);
        int ans=p.ff;
        int gg=p.ss.ff;
        int numm=p.ss.ss;
        int x=xx[numm],y=yy[numm],pr=last[numm],type=tt[numm];
        //cout<<x<<" "<<y<<" "<<pr<<" "<<type<<" "<<ans<<" "<<gg<<endl;
        if (pr==n*n) {cout<<ans-1<<" "<<gg<<endl; return 0;}
        up(x,y,pr,1,ans+1,gg+1);
        up(x,y,pr,2,ans+1,gg+1);
        up(x,y,pr,3,ans+1,gg+1);
        if (type==1)
        {
            for (int l=1; l<=n; l++)
            for (int r=1; r<=n; r++)
            if (min(abs(l-x),abs(r-y))==1&&max(abs(l-x),abs(r-y))==2)
            {
                if (a[l][r]==pr+1) up(l,r,pr+1,1,ans+1,gg);
                else up(l,r,pr,1,ans+1,gg);
            }
        } else
        if (type==2)
        {
            for (int l=1; l<=n; l++)
            for (int r=1; r<=n; r++)
            if (l+r==x+y||l-r==x-y)
            {
                if (a[l][r]==pr+1) up(l,r,pr+1,2,ans+1,gg);
                else up(l,r,pr,2,ans+1,gg);
            }
        } else
        {
            for (int l=1; l<=n; l++)
            for (int r=1; r<=n; r++)
            if (l==x||r==y)
            {
                if (a[l][r]==pr+1) up(l,r,pr+1,3,ans+1,gg);
                else up(l,r,pr,3,ans+1,gg);
            }
        }
    }
}