#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int l=0,r=min(a,b);
        int ans=0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int A = mid , B = mid, C = (a+b+c)-2*mid;
            if (C>=mid)ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
}