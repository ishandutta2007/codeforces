#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 2e6 + 11;
int kol[N];
string ss[N];
int v[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int sz=0;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        ss[i]=s;
        for (int j=1; j<=k; j++)
        {
            int l;
            cin>>l;
            if (v[l]==0) v[l]=i; else
            if ((int)s.size()>(int)ss[v[l]].size()) v[l]=i;
            sz=max(sz,l+(int)s.size()-1);
        }
    }
    int x=-1,k=0;
    int num;
    for (int i=1; i<=sz; i++)
    {
        int d=v[i];
        if (d!=0)
        {
            if (x==-1) {num=d; x=0;} else
            if (ss[d].size()>ss[num].size()-x) {num=d; x=0;}
        }
        if (x==-1) cout<<"a"; else
        {
            cout<<ss[num][x];
            x++;
            if (x==(int)ss[num].size()) x=-1;
        }
    }
}