#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N],b[N],c[N],d[N];
int use[N];

bool cmp(int l, int r)
{
    if (a[l]!=a[r]) return (a[l]<a[r]);
    if (b[l]!=b[r]) return (b[l]<b[r]);
    if (c[l]!=c[r]) return (c[l]<c[r]);
    return (l<r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            d[i]=i;
        }
    sort(d+1,d+n+1,cmp);
    for (int p=1; p<=n/2; p++)
    {
        vector<int> nums;
        for (int i=1; i<=n; i++)
            if (use[d[i]]==0) nums.pb(d[i]);
        int res=0;
        for (int j=1; j<nums.size(); j++)
            if (a[nums[j]]==a[nums[j-1]]&&b[nums[j]]==b[nums[j-1]])
            {
                cout<<nums[j-1]<<" "<<nums[j]<<"\n";
                res=1;
                use[nums[j-1]]=1;
                use[nums[j]]=1;
                break;
            }
        for (int j=1; j<nums.size(); j++)
            if (a[nums[j]]==a[nums[j-1]]&&res==0)
        {
            cout<<nums[j-1]<<" "<<nums[j]<<"\n";
            res=1;
            use[nums[j-1]]=1;
            use[nums[j]]=1;
            break;
        }
        if (res==0)
        {
            cout<<nums[0]<<" "<<nums[1]<<"\n";
            res=1;
            use[nums[0]]=1;
            use[nums[1]]=1;
        }
    }
}