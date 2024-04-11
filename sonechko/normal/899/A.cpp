#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l==1) k1++; else k2++;
    }
    int res=min(k1,k2);
    k1-=res;
    k2-=res;
    res+=k1/3;
    cout<<res<<endl;
}