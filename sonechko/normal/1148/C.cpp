#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 5e5 + 11;

int a[N],pos[N];
vector<pair<int,int> > ans;

void swapp(int l, int r)
{
    swap(a[l],a[r]);
    ans.pb(mp(l,r));
    pos[a[l]]=l;
    pos[a[r]]=r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }

    for (int d=n/2+1; d<n; d++)
    {
        int c=pos[d];
        if (c==d) {} else
        if (c==1) swapp(1,d); else
        if (c<=n/2) {swapp(n,c); swapp(1,n); swapp(1,d);} else
        {swapp(1,c); swapp(1,d);}
    }
    for (int d=2; d<=n/2; d++)
    {
        int c=pos[d];
        if (c==d) {} else
        if (c<=n/2) {swapp(c,n); swapp(n,d);} else
        {swapp(n,d);}
    }
    if (pos[1]!=1) swapp(1,n);
    cout<<ans.size()<<endl;
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j].ff<<" "<<ans[j].ss<<"\n";
}
/**

1 2 3 4 5 6 7 8 9 10

1 - 6..10
2 - 7..10
3 - 8..10
4 - 9..10
5 - 10..10

**/