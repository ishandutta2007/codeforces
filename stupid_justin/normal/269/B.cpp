#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int f[5005][5005];
int a[N];
vector<int> num;
int n,m,ans;
signed main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
	{
        double x;
        cin>>a[i]>>x;
    }
    num.clear();
    num.push_back(a[1]);
    for (int i=2;i<=n;i++)
	{
        if(a[i]>=num.back())
            num.push_back(a[i]);
        else{
            int pos=upper_bound(num.begin(),num.end(),a[i])-num.begin();
            num[pos]=a[i];
        }
    }
    ans=n-(int)num.size();
    cout<<ans<<endl;
}