#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int a[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (r!=n) {cout<<"NO"<<endl; return 0;}
        a[l]++;

    }
    vector<int> vv;
    for (int i=1; i<n; i++)
        if (a[i]==0) vv.pb(i);
    vector<pair<int,int> > v;
    for (int i=n-1; i>=1; i--)
        if (a[i]==0&&use[i]==0) {cout<<"NO"<<endl; return 0;} else
        if (a[i]!=0)
        {
            int d=n;
            while (vv.size()>0&&a[i]>1)
            {
                v.pb(mp(d,vv.back()));
                use[vv.back()]=1;
                d=vv.back();
                vv.pop_back();
                a[i]--;
            }
            if (a[i]>1) {cout<<"NO"<<endl; return 0;}
            v.pb(mp(d,i));
        }
    if (vv.size()!=0) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int j=0; j<v.size(); j++)
        cout<<v[j].ff<<" "<<v[j].ss<<endl;
}