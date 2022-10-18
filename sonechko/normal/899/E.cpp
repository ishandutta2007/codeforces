#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 3e5 + 11;
int nex[N],pre[N],ks[N],p[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int x=0;
    int kol_g=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l!=x)
            {
                kol_g++;
                pre[kol_g]=kol_g-1;
                nex[kol_g]=kol_g+1;
                ks[kol_g]=1;
                p[kol_g]=l;
                x=l;
            } else ks[kol_g]++;
    }
    set<pair<int,int> > st;
    for (int i=1; i<=kol_g; i++)
    {
        st.insert(mp(-ks[i],i));
    }
    int ans=0;
    while (st.size()>0)
    {
        pair<int,int> pp = *st.begin();
        st.erase(pp);
        int num=pp.ss;
        ans++;
        int p1=pre[num];
        int p2=nex[num];
        if (p[p1]==p[p2]&&p1>0)
        {
            ks[num]=ks[p1]+ks[p2];
            st.erase(mp(-ks[p1],p1));
            st.erase(mp(-ks[p2],p2));
            st.insert(mp(-ks[num],num));
            p[num]=p[p1];
            nex[pre[p1]]=num;
            pre[nex[p2]]=num;
            pre[num]=pre[p1];
            nex[num]=nex[p2];
        } else
        {
            pre[nex[num]]=pre[num];
            nex[pre[num]]=nex[num];
        }
    }
    cout<<ans<<endl;
}