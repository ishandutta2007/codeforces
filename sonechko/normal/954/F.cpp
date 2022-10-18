#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

struct oblachko
{
    int d[3][3];
    int sz;
    oblachko ()
    {
        memset(d,0,sizeof(d));
    }
};

oblachko mn(oblachko a, oblachko b)
{
    oblachko c;
    c.sz=a.sz;
    for (int i=0; i<a.sz; i++)
    for (int j=0; j<b.sz; j++)
    for (int k=0; k<a.sz; k++)
    c.d[i][j]=(1ll*c.d[i][j]+a.d[i][k]*1ll*b.d[k][j])mod;
    return c;
}

oblachko steps(oblachko a, long long st)
{
    oblachko ans;
    ans.sz=a.sz;
    ans.d[0][0]=1;
    ans.d[1][1]=1;
    ans.d[2][2]=1;
    while (st>0)
    {
        if (st%2ll==1ll) {ans=mn(ans,a); st--;} else
        {
            a=mn(a,a);
            st/=2ll;
        }
    }
    return ans;
}

void write(oblachko a)
{
    for (int i=0; i<a.sz; i++)
    {
        for (int j=0; j<a.sz; j++)
                cout<<a.d[i][j]<<" ";
        cout<<endl;
    }
}

long long dp[3],dd[3],kol[3];
bool use[3],uss[3];
vector<long long> vv;
map<long long,bool> mt;
map<long long,int> ahh[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    oblachko start3;
    start3.sz=3;
    start3.d[0][0]=start3.d[0][1]=start3.d[1][0]=start3.d[1][1]=start3.d[1][2]=
    start3.d[2][1]=start3.d[2][2]=1;
    oblachko start2;
    start2.sz=2;
    start2.d[0][0]=start2.d[0][1]=start2.d[1][0]=start2.d[1][1]=1;
    int n;
    long long m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        long long l,r;
        int a;
        cin>>a>>l>>r;
        a--;
        if (mt[l]==0) {mt[l]=1; vv.pb(l);}
        if (mt[r+1]==0) {mt[r+1]=1; vv.pb(r+1);}
        ahh[a][l]++;
        ahh[a][r+1]--;
    }
    if (mt[m]==0) vv.pb(m);
    if (mt[2]==0) vv.pb(2);
    ahh[0][m]++;
    ahh[2][m]++;
    sort(vv.begin(),vv.end());
    dp[0]=0;
    dp[1]=1;
    dp[2]=0;
    long long pos=1;
    use[0]=0;
    use[1]=0;
    use[2]=0;
    for (int i=0; i<vv.size(); i++)
    {
        long long ps=vv[i];
        for (int j=0; j<3; j++)
        {
            uss[j]=use[j];
            dd[j]=0;
        }
        for (int j=0; j<3; j++)
        {
            kol[j]+=ahh[j][ps];
            if (kol[j]==0) uss[j]=0; else uss[j]=1;
        }
        if (use[0]==0)
        {
            if (uss[0]==0) dd[0]=(dd[0]+dp[0])mod;
            if (uss[1]==0) dd[1]=(dd[1]+dp[0])mod;
        }
        if (use[1]==0)
        {
            if (uss[0]==0) dd[0]=(dd[0]+dp[1])mod;
            if (uss[1]==0) dd[1]=(dd[1]+dp[1])mod;
            if (uss[2]==0) dd[2]=(dd[2]+dp[1])mod;
        }
        if (use[2]==0)
        {
            if (uss[1]==0) dd[1]=(dd[1]+dp[2])mod;
            if (uss[2]==0) dd[2]=(dd[2]+dp[2])mod;
        }
        for (int j=0; j<3; j++)
        {
            use[j]=uss[j];
            dp[j]=dd[j];
        }
        long long len;
        if (vv.size()==i+1) len=m-vv[i]; else len=vv[i+1]-vv[i]-1;
        if (len!=0)
        {
            if (uss[0]==1&&uss[1]==1&&uss[2]==1) {cout<<0<<endl; return 0;}
            if (uss[0]==0&&uss[1]==0&&uss[2]==1)
            {
                oblachko c=steps(start2,len);
                dp[0]=(c.d[0][0]*1ll*dd[0]+c.d[0][1]*1ll*dd[1])mod;
                dp[1]=(c.d[1][0]*1ll*dd[0]+c.d[1][1]*1ll*dd[1])mod;
            }
            if (uss[0]==1&&uss[1]==0&&uss[2]==0)
            {
                oblachko c=steps(start2,len);
                dp[1]=(c.d[0][0]*1ll*dd[1]+c.d[0][1]*1ll*dd[2])mod;
                dp[2]=(c.d[1][0]*1ll*dd[1]+c.d[1][1]*1ll*dd[2])mod;
            }
            if (uss[0]==0&&uss[1]==0&&uss[2]==0)
            {
                oblachko c=steps(start3,len);
                dp[0]=(c.d[0][0]*1ll*dd[0]+c.d[0][1]*1ll*dd[1]+c.d[0][2]*1ll*dd[2])mod;
                dp[1]=(c.d[1][0]*1ll*dd[0]+c.d[1][1]*1ll*dd[1]+c.d[1][2]*1ll*dd[2])mod;
                dp[2]=(c.d[2][0]*1ll*dd[0]+c.d[2][1]*1ll*dd[1]+c.d[2][2]*1ll*dd[2])mod;
            }
        }
       // cout<<uss[0]<<uss[1]<<uss[2]<<endl;
        //cout<<vv[i]+len<<"  "<<dd[0]<<" "<<dd[1]<<" "<<dd[2]<<"  "<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl;
    }
    cout<<dp[1]<<endl;
}