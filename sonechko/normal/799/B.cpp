#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 2e5 + 11;
set<pair<int,int> > st1,st2,st3;
int a[N],b[N],c[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int i=1; i<=n; i++)
        {
            cin>>c[i];
            if (b[i]==1||c[i]==1) st1.insert(mp(a[i],i));
            if (b[i]==2||c[i]==2) st2.insert(mp(a[i],i));
            if (b[i]==3||c[i]==3) st3.insert(mp(a[i],i));
        }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        if (l==1)
        {
            if (st1.empty()) cout<<-1<<" "; else
            {
                pair<int,int> pp=*st1.begin();
                st1.erase(pp);
                cout<<pp.ff<<" ";
                if (b[pp.ss]==2||c[pp.ss]==2)
                    st2.erase(pp);
                if (b[pp.ss]==3||c[pp.ss]==3)
                    st3.erase(pp);
            }
        }
        if (l==2)
        {
            if (st2.empty()) cout<<-1<<" "; else
            {
                pair<int,int> pp=*st2.begin();
                st2.erase(pp);
                cout<<pp.ff<<" ";
                if (b[pp.ss]==1||c[pp.ss]==1)
                    st1.erase(pp);
                if (b[pp.ss]==3||c[pp.ss]==3)
                    st3.erase(pp);
            }
        }
        if (l==3)
        {
            if (st3.empty()) cout<<-1<<" "; else
            {
                pair<int,int> pp=*st3.begin();
                st3.erase(pp);
                cout<<pp.ff<<" ";
                if (b[pp.ss]==1||c[pp.ss]==1)
                    st1.erase(pp);
                if (b[pp.ss]==2||c[pp.ss]==2)
                    st2.erase(pp);
            }
        }
    }
}