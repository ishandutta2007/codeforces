#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        vector b(n,vector<int>(m,-1));
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        bool flag=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(j>0&&j<m-1&&a[i][j-1]=='*'&&a[i][j]=='*'&&a[i][j+1]=='*') {flag=0;}
                if(i>0&&i<n-1&&a[i-1][j]=='*'&&a[i][j]=='*'&&a[i+1][j]=='*') flag=0;
                if(a[i][j]=='*'&&(i==0||a[i-1][j]=='.')&&(i==n-1||a[i+1][j]=='.')&&(j==0||a[i][j-1]=='.')&&(j==m-1||a[i][j+1]=='.')) flag=0;
            }
        }
        if(!flag)
        {
            cout<<"NO\n";
            return;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]=='.') continue;
                if(j>0&&a[i][j-1]=='*'&&i>0&&a[i-1][j]=='*')
                {
                    b[i][j-1]=b[i][j]=b[i-1][j]=i*n+j;
                }
                if(i>0&&a[i-1][j]=='*'&&j<m-1&&a[i][j+1]=='*')
                {
                    b[i][j+1]=b[i][j]=b[i-1][j]=i*n+j;
                }
                if(j<m-1&&a[i][j+1]=='*'&&i<n-1&&a[i+1][j]=='*')
                {
                    b[i][j+1]=b[i][j]=b[i+1][j]=i*n+j;
                }
                if(i<n-1&&a[i+1][j]=='*'&&j>0&&a[i][j-1]=='*')
                {
                    b[i][j-1]=b[i][j]=b[i+1][j]=i*n+j;
                }
            }
        }
        int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]=='.')continue;
                if(b[i][j]==-1)
                {
                    flag=0;break;
                }
                for(int k=0;k<8;++k)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x<0||y<0||x>=n||y>=m) continue;
                    if(b[x][y]==-1) continue;
                    if(b[x][y]!=b[i][j]) {flag=0;}
                }
            }
        }
        if(!flag)
        {
            cout<<"NO\n";return;
        }
        cout<<"YES\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/