#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 100000 + 11;
int a[N],use[N],v1,v2,v3;
vector<int> v[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            if (a[i]==1) v1++;
            if (a[i]==2) v2++;
            if (a[i]==3) v3++;
            if (a[i]==7||a[i]==5) {cout<<-1<<endl; return 0;}
        }
    int p=0;
    for (int i=1; i<=n; i++)
        if (a[i]==4)
    {
        if (v1==0||v2==0) {cout<<-1<<endl; return 0;}
        p++;
        v[p].pb(1);
        v[p].pb(2);
        v[p].pb(4);
        v1--;
        v2--;
    } else
    if (a[i]==6)
    {
        if (v1==0||(v2+v3==0)) {cout<<-1<<endl; return 0;}
        p++;
        v[p].pb(1);
        if (v3!=0)
        {
            v[p].pb(3);
            v3--;
        } else
        {
            v[p].pb(2);
            v2--;
        }
        v[p].pb(6);
    }
    if (p!=n/3) {cout<<-1<<endl; return 0;}
    for (int i=1; i<=p; i++)
        cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";

}