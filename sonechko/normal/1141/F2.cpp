#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 3e6 + 11;

int a[N],s[N];
vector<pair<int,int> > b[N];
map<int,int> mt;
int kk;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++)
    {
        int sum=s[j]-s[i-1];
        if (mt[sum]==0) {kk++; mt[sum]=kk;}
        b[mt[sum]].pb(mp(j,i));
    }
    vector<int> l1,r1;
    for (int i=1; i<=kk; i++)
    {
        sort(b[i].begin(),b[i].end());
        int last=0;
        vector<int> l2,r2;
        for (int j=0; j<b[i].size(); j++)
            if (b[i][j].ss>last)
            {
                l2.pb(b[i][j].ss);
                r2.pb(b[i][j].ff);
                last=b[i][j].ff;
            }
        if (l2.size()>l1.size())
        {
            l1=l2;
            r1=r2;
        }
    }
    cout<<l1.size()<<endl;
    for (int j=0; j<l1.size(); j++)
        cout<<l1[j]<<" "<<r1[j]<<endl;
}