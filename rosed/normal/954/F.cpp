#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    int c[N],num;
    struct matrix
    {
        int g[4][4];
        inline void clear()
        {
            memset(g,0,sizeof(g));
        }
        inline matrix operator * (const matrix &t) const
        {
            matrix ret;
            ret.clear();
            for(int i=1;i<=3;++i)
            {
                for(int j=1;j<=3;++j)
                {
                    for(int k=1;k<=3;++k)
                    {
                        ret.g[i][j]=(ret.g[i][j]+g[i][k]*t.g[k][j])%mod;
                    }
                }
            }
            return ret;
        }
    }T,ans,tran,tmp;
    inline matrix matrixfast(matrix x,int k)
    {
        matrix ret;
        ret.clear();
        ret.g[1][1]=ret.g[2][2]=ret.g[3][3]=1;
        while(k)
        {
            if(k&1) ret=ret*x;
            x=x*x;
            k>>=1;
        }
        return ret;
    }
    typedef pair<int,int> pr;
    vector<pr> q[4];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            int x,l,r;cin>>x>>l>>r;
            c[++num]=l-1,c[++num]=r;
            q[x].emplace_back(pr(l,1));
            q[x].emplace_back(pr(r+1,-1));
        }
        for(int k=1;k<=3;++k)
        {
            sort(q[k].begin(),q[k].end());
            int s=q[k].size();
            for(int i=1;i<s;++i)
            {
                q[k][i].second+=q[k][i-1].second;
            }
        }
        ans.clear();
        ans.g[1][2]=1;
        tran.clear();
        tran.g[1][1]=tran.g[2][1]=tran.g[1][2]=tran.g[2][2]=tran.g[3][2]=tran.g[2][3]=tran.g[3][3]=1;
        sort(c+1,c+num+1);
        num=unique(c+1,c+num+1)-c-1;
        int pre=1;
        for(int i=1;i<=num;++i)
        {
            int now=c[i];
            int len=now-pre;
            if(!len) continue;
            tmp=tran;
            for(int k=1;k<=3;++k)
            {
                int pos=upper_bound(q[k].begin(),q[k].end(),pr(now,1e18))-q[k].begin()-1;
                //if(now==2&&k==2) cout<<k<<' '<<q[k][0].first<<"!!"<<endl;
                if(pos>=0&&q[k][pos].second>0)
                {
                    for(int j=1;j<=3;++j) tmp.g[j][k]=0;
                }
            }
            //cout<<now<<"!!"<<endl;
            // for(int j=1;j<=3;++j)
            // {
            //     for(int k=1;k<=3;++k)
            //     {
            //         cout<<tmp.g[j][k]<<" \n"[k==3];
            //     }
            // }
            cout<<'\n';
            tmp=matrixfast(tmp,len);
            ans=ans*tmp;
            pre=now;
        }
        // matrix qwq=ans;
        // qwq=qwq*tran*tran;
        // cout<<qwq.g[1][1]<<' '<<qwq.g[1][2]<<' '<<qwq.g[1][3]<<'\n';
        //cout<<m-pre<<"!!"<<endl;
        tmp=matrixfast(tran,m-pre);
        ans=ans*tmp;
        cout<<ans.g[1][2]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
0 5


*/