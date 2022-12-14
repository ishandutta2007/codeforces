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
        int n;
        cin>>n;
        for (int i=0;i<100;i++)
        {
            a[i]=0;
        }
        while(n--)
        {
            int x;
            cin>>x;
            int y=0;
            while(x%2==0)x/=2,y++;
            a[y]++;
        }
        for (int i=0;i<=10;i++)
        {
            a[i+1]+=a[i]/2;
        }
        if (a[11])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}