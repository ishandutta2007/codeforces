#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int A,B;
    cin>>A>>B;
    int k1,k2;
    cin>>k1>>k2;
    if (k1>k2)swap(k1,k2),swap(A,B);
    int n;
    cin>>n;
    // MAX
    int extra = A*(k1-1)+B*(k2-1);
    int mx = A+B;
    if (extra<n){
        mx -= n-extra;
    }
    mx = max(0,mx);
    // MIN
    int cur=n;
    int ret=0;
    for (int i=0;i<A;i++)
    {
        if (cur>=k1)cur-=k1,ret++;
    }
    for (int i=0;i<B;i++)
    {
        if (cur>=k2)cur-=k2,ret++;
    }
    cout<<A+B-mx<<' '<<ret<<endl;
}