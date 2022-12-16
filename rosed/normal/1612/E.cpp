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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> id(200000);
        vector<double> val(200000);
        typedef array<int,2> pr;
        vector<pr> a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i][0]>>a[i][1];
            --a[i][0];
        }
        double ret=0;
        vector<int> ans;
        for(int k=1;k<=100;++k)
        {
            for(int i=0;i<200000;++i) id[i]=i;
            double ex=0;
            vector<int> tmp;
            for(int i=0;i<n;++i)
            {
                if(a[i][1]>=k) val[a[i][0]]+=1;
                else val[a[i][0]]+=1.0*a[i][1]/k;
            }
            sort(id.begin(),id.end(),[&](int x,int y){return val[x]>val[y];});
            for(int j=1;j<=k;++j)
            {
                ex+=val[id[j-1]];
                tmp.emplace_back(id[j-1]);
            }
            for(int i=0;i<n;++i) val[a[i][0]]=0;
            //cout<<k<<' '<<ex<<endl;
            if(ex>ret) ret=ex,ans=tmp;
            //cout<<ex<<"!!"<<endl;
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<'\n';
        for(int x:ans) cout<<x+1<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/