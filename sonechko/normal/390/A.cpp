#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int kol1[N],kol2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (kol1[l]==0) ans1++;
        if (kol2[r]==0) ans2++;
        kol1[l]=1;
        kol2[r]=1;
    }
    cout<<min(ans1,ans2);
}