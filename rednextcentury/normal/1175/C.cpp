#include <bits/stdc++.h>
using namespace std;
long long best = -1;
long long a[1000000];
int k;
int n;
bool check(long long mid) {
    mid=mid*2;
    int l=0;
    int num=0;
    for (int r=0;r<n;r++) {
        num++;
        while(a[r]-a[l]>mid)
            l++,num--;
        if (num>k) {
            best = (a[l]+a[r])/2;
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        best=-1;
        for (int i=0;i<n;i++)
            cin>>a[i];
        long long l=0,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if (check(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<best<<endl;
    }
}