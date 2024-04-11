#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 17;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            if (a[i]%2==0) v1.pb(a[i]); else v2.pb(a[i]);
        }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int sum=0;
    int i=v1.size()-1;
    while (i>=0)
    {
        if (v1[i]>0) {sum+=v1[i]; i--;} else break;
    }
    sum+=v2[v2.size()-1];
    i=v2.size()-2;
    while (i>0)
    {
        if (v2[i]+v2[i-1]>0) {sum+=v2[i]+v2[i-1]; i-=2;} else break;
    }
    cout<<sum<<endl;
}