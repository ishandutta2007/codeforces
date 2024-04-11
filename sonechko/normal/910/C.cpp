#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int kol[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int k=1;
        for (int j=s.size()-1; j>=0; j--)
        {
            char ch=s[j];
            int p=s[j]-'a';
            kol[p]+=k;
            k*=10;
        }
        use[s[0]-'a']=1;
    }
    int p=0,res=0;
    for (int x=0; x<=9; x++)
        if (use[x]==0) p=x;
    for (int x=0; x<=9; x++)
        if (kol[x]>kol[p]&&use[x]==0) p=x;
    vector<int> v;
    for (int x=0; x<=9; x++)
        if (x!=p) v.pb(kol[x]);
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++)
        res+=v[i]*(9-i);
    cout<<res<<endl;
}