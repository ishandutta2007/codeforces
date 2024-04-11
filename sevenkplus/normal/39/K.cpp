#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<PII,PII> PI4;
#define pb push_back
#define mp make_pair
#define m4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define fi first
#define se second
#define x1 fi.fi
#define y1 fi.se
#define x2 se.fi
#define y2 se.se
char a[1010][1010];
int n,m,k;vector<PI4> r;vector<int> px;ll S;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(a[i][j]=='*')
        {
            int i1=i,j1=j;
            while(a[i1][j]=='*')i1++;i1--;
            while(a[i][j1]=='*')j1++;j1--;
            for(int k=i;k<=i1;k++)
                for(int l=j;l<=j1;l++)a[k][l]='.';
            r.pb(m4(i,j,i1,j1)),
            px.pb(i),px.pb(i1);
        }
    px.pb(0),sort(px.begin(),px.end()),
    px.erase(unique(px.begin(),px.end()),px.end());
    for(int i=0;i<(int)px.size();i++)
        for(int j=i;j<(int)px.size();j++)
        {
            int lw=px[i],rw=px[j];
            vector<PII> py;
            for(int k=0;k<(int)r.size();k++)
                if(lw<=r[k].x1&&r[k].x1<=rw||lw<=r[k].x2&&r[k].x2<=rw||r[k].x1<=lw&&rw<=r[k].x2)
                    if(lw<=r[k].x1&&r[k].x2<=rw)py.pb(mp(r[k].y1,-1)),py.pb(mp(r[k].y2,1));
                    else py.pb(mp(r[k].y1,-100)),py.pb(mp(r[k].y2,100));
            py.pb(mp(0,0)),sort(py.begin(),py.end());
            for(int C=1;C<=3;C++)
                for(int l=0,r=0,c=0,sr=0,sl=0;l<(int)py.size();l++)
                {
                    while(r<(int)py.size()&&(sr!=0||c<C))
                        c+=max(py[r].se,0),sr+=py[r++].se;
                    if(c==C&&sl==0&&sr==0)
                        S+=(ll)(i==0?1:px[i]-px[i-1])*(j==(int)px.size()-1?n-px[j]:px[j+1]-px[j])
                            *(l==0?1:py[l].fi-py[l-1].fi)*(r==(int)py.size()?m-py[r-1].fi:py[r].fi-py[r-1].fi);
                    c-=max(py[l].se,0),sl+=py[l].se;
                }
        }
    printf("%I64d\n",S);
    return 0;
}