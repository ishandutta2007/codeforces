#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1),pos(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int ans=0;
    int tl=pos[0],tr=pos[0];
    for(int i=0;i<n;++i)
    {
        tl=min(tl,pos[i]);
        tr=max(tr,pos[i]);
        // cout<<i<<"XXX"<<endl;
        // cout<<tl<<' '<<tr<<"!!"<<endl;
        int p=pos[i+1];
        int len=2*(i+1);
        if(tl<=pos[i+1]&&pos[i+1]<=tr) continue;
        if(tr-tl+1>len) continue;
        // if(tr-tl!=i) continue;
        
        int ql=max(1ll,tr-len+1),qr=min(n,tl+len-1);
        if(p<tl) ql=max(ql,p+1);
        if(p>tr) qr=min(qr,p-1);
        if(ql>qr) continue;
        // cout<<ql<<' '<<qr<<"!!!!!!"<<endl;
        int dl=min(n,ql+len-1)-tr+1;
        int dr=qr-tr+1;
        // cout<<dl<<' '<<dr<<"---------"<<endl;
        if(dl>=dr)
        {
            // cout<<"!!!"<<endl;
            ans+=(tl-ql+1)*dr;
            // cout<<(tl-ql+1)*dr<<"!!!"<<endl;
        }
        else
        {
            ans+=(dl+dr)*(dr-dl+1)/2;
            ans+=((tl-ql+1)-(dr-dl+1))*dr;
            // cout<<((tl-ql+1)-(dr-dl+1))*dr<<"!!"<<endl;
             // cout<<i<<' '<<qr<<' '<<tr<<' '<<dr<<"!!!!"<<endl;
        }
        // cout<<ans<<"!!=="<<endl;
    }
    cout<<ans<<'\n';
}
signed main()
{
    // freopen("data.in","r",stdin);
    //  freopen("red.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}

/*
8 0 7 2 9 11 1 4 5 3 14 12 10 6 13



*/