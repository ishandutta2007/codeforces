#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ss=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ss+=a[i];
    }
    if (ss%k!=0) {cout<<"No"<<endl; return 0;}
    int s=0;
    ss/=k;
    vector<int> kol;
    kol.pb(0);
    for (int i=1; i<=n; i++)
    {
        s+=a[i];
        if (s>ss) {cout<<"No"<<endl; return 0;}
        kol.back()++;
        if (s==ss)
        {
            s=0;
            kol.pb(0);
        }
    }
    kol.pop_back();
    cout<<"Yes"<<endl;
    for (int j=0; j<kol.size(); j++)
        cout<<kol[j]<<" ";
    cout<<endl;
}