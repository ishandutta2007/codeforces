#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pf push_front

const int N = 1e6 + 11;

vector<int> ans;
int a[4];
vector<int> v[N];
int x[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a[0]>>a[1]>>a[2]>>a[3];

    if (a[0]+a[3]==0)
    {
        if (abs(a[1]-a[2])>1) return cout<<"NO", 0;
        while (a[1]+a[2]>0)
        {
            if ((int)ans.size()==0)
            {
                if (a[1]>a[2]) ans.pb(1); else ans.pb(2);
            } else
            if (ans.back()==1) ans.pb(2); else ans.pb(1);
            a[ans.back()]--;
        }
        cout<<"YES\n";
        for (int j=0; j<ans.size(); j++)
            cout<<ans[j]<<" ";
        return 0;
    }

    int n=a[0]+a[3];
    for (int i=1; i<=n; i++)
        if (i<=a[0]) x[i]=0; else x[i]=3;
    for (int i=1; i<=n; i++)
        if (i<a[0]) {v[i].pb(1); a[1]--;} else
        if (i==a[0]&&i<n) {v[i].pb(1); v[i].pb(2); a[1]--; a[2]--;} else
        if (i<a[0]+a[3]) {v[i].pb(2); a[2]--;}
    if (a[1]<0||a[2]<0) return cout<<"NO", 0;
    if (a[3]==0)
    {
        if (a[1]-a[2]>2||a[2]>a[1]) return cout<<"NO", 0;
        cout<<"YES\n";
        if (a[1]-a[2]==2)
        {
            cout<<1<<" ";
            a[1]--;
        }
        for (int i=1; i<=n; i++)
        {
            cout<<x[i]<<" ";
            for (int j=0; j<v[i].size(); j++)
                cout<<v[i][j]<<" ";
        }
        int last=0;
        while (a[1]+a[2]>0)
        {
            if (last==0||last==2) {cout<<1<<" "; a[1]--; last=1;} else
            {
                cout<<2<<" ";
                a[2]--;
                last=2;
            }
        }
        return 0;
    }
    if (a[0]==0)
    {
        if (a[2]-a[1]>2||a[1]>a[2]) return cout<<"NO", 0;
        cout<<"YES\n";
        if (a[2]-a[1]==2)
        {
            cout<<2<<" ";
            a[2]--;
        }
        for (int i=1; i<=n; i++)
        {
            cout<<x[i]<<" ";
            for (int j=0; j<v[i].size(); j++)
                cout<<v[i][j]<<" ";
        }
        int last=3;
        while (a[1]+a[2]>0)
        {
            if (last==2) {cout<<1<<" "; a[1]--; last=1;} else
            {
                cout<<2<<" ";
                a[2]--;
                last=2;
            }
        }
        return 0;
    }
    if (abs(a[1]-a[2])>1) return cout<<"NO", 0;
    if (a[0]>0&&a[1]>a[2])
    {
        cout<<"YES\n";
        while (a[1]>0)
        {
            if (a[1]>a[2]) {cout<<1<<" "; a[1]--;}
            else {cout<<2<<" "; a[2]--;}
        }
        for (int i=1; i<=n; i++)
        {
            cout<<x[i]<<" ";
            for (int j=0; j<v[i].size(); j++)
                cout<<v[i][j]<<" ";
        }
        return 0;
    }
    if (a[3]>0&&a[2]>a[1])
    {
        cout<<"YES\n";
        for (int i=1; i<=n; i++)
        {
            cout<<x[i]<<" ";
            for (int j=0; j<v[i].size(); j++)
                cout<<v[i][j]<<" ";
        }
        while (a[2]>0)
        {
            if (a[2]>a[1]) {cout<<2<<" "; a[2]--;}
            else {cout<<1<<" "; a[1]--;}
        }
        return 0;
    }
    if (a[1]!=a[2]) return cout<<"NO", 0;
    cout<<"YES\n";
    for (int i=1; i<=n; i++)
    {
        cout<<x[i]<<" ";
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        if (v[i].size()>0&&a[1]+a[2]>0)
        {
            int l=v[i].back();
            while (a[1]>0||a[2]>0)
            {
                if (l==1) {cout<<2<<" "; a[2]--; l=2;} else
                    {
                        cout<<1<<" "; a[1]--; l=1;
                    }
            }
        }
    }
}
/**
   0   0   0   0   3    3    3    3
+

0  1  0  1  0


0   0   0   0   3   3   3   3   3
  1   1   1   12  2   2   2   2


   0
  1 1

1>2


   0   0    0
**/