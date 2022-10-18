#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 3e6 + 11;

bool use[N];

bool good(int l)
{
    int gg=1;
    for (int d=2; d*d<=l; d++)
        if (l%d==0)
    {
        while (l%d==0)
            l/=d;
        if (use[d]==1) gg=0;
    }
    if (l!=1&&use[l]==1) gg=0;
    return gg;
}
void up(int l)
{
    for (int d=2; d*d<=l; d++)
        if (l%d==0)
    {
        while (l%d==0)
            l/=d;
        use[d]=1;
    }
    if (l!=1) use[l]=1;
}

int main()
{
    vector<int> vv;
    for (int i=2; i<=3000000; i++)
        if (use[i]==0)
    {
        vv.pb(i);
        if (i*1ll*i<=3000000)
        {
            for (int j=i*i; j<=3000000; j+=i)
                use[j]=1;
        }
    }
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        int xx=l,gg=0;
        if (good(l)) {up(l); cout<<l<<" ";} else
        {
            int cc=0;
            for (int p=xx; p<=1000000; p++)
            if (good(p)) {cc=p; break;}
            up(cc);
            cout<<cc<<" ";
            int kol=n-i;
            for (int i=0; i<vv.size(); i++)
                if (use[vv[i]]==0&&kol>0)
            {
                cout<<vv[i]<<" ";
                kol--;
            }
            cout<<endl;
            return 0;
        }
    }
}