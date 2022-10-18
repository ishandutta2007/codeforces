#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

vector<int> v[N];
map<int,bool> d[N];
int a[N],b[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        d[l][r]=1;
        d[r][l]=1;
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int kol=1;
    use[1]=1;
    if (a[1]!=1) {cout<<"No"<<endl; return 0;}
    for (int i=1; i<=kol; i++)
    {
        int l=a[i];
        int kk=0;
        for (int j=0; j<v[l].size(); j++)
            if (use[v[l][j]]==0) kk++;
        for (int i=1; i<=kk; i++)
        {
            kol++;
            int c=a[kol];
            if (d[l][c]==0) {cout<<"No"<<endl; return 0;}
            use[c]=1;
        }
    }
    cout<<"Yes"<<endl;
}