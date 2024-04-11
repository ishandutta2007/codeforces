#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e5 + 11;

int main()
{
    int n,m;
    cin>>m>>n;
    set<pair<int,int> > s1,s2;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        s1.insert(mp(l,i));
        s2.insert(mp(l,i));
    }
    int ans1=0,ans2=0;
    for (int i=1; i<=m; i++)
    {
        pair<int,int> p1=*s1.begin();
        ans1+=p1.ff;
        s1.erase(p1);
        if (p1.ff!=1) s1.insert(mp(p1.ff-1,p1.ss));
        pair<int,int> p2=*s2.rbegin();
        ans2+=p2.ff;
        s2.erase(p2);
        if (p2.ff!=1) s2.insert(mp(p2.ff-1,p2.ss));

    }
    cout<<ans2<<" "<<ans1<<endl;
}