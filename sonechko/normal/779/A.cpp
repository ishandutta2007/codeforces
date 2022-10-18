#include<bits/stdc++.h>
using namespace std;
int k1[6],k2[6];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            k1[l]++;
        }
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        k2[l]++;
    }
    for (int i=1; i<=5; i++)
    if ((k1[i]+k2[i])%2==1) {cout<<"-1"<<endl; return 0;}
    int ans1=0,ans2=0;
    for (int i=1; i<=5; i++)
        if (k1[i]>k2[i]) ans1+=k1[i]-(k1[i]+k2[i])/2; else ans2+=k2[i]-(k2[i]+k1[i])/2;
    cout<<max(ans1,ans2)<<endl;
}