#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    vector<int> v;
    v.pb(1);
    for (int i=n-1; i>=1; i--)
    {
        if (a[i]==a[i+1]) v.back()++; else
        {
            v.pb(1);
        }
    }
    for (int i=0; i<v.size(); i++)
        if (v[i]%2==1)
    {
        cout<<"Conan"<<endl;
        return 0;
    }
    cout<<"Agasa"<<endl;
}