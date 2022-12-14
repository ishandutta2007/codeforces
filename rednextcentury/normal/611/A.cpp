# include<bits/stdc++.h>
using namespace std;
int a[]={52,52,52,52,53,53,52};
int b[]={31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int n;
    string g,h;
    cin>>n>>g>>g;
    if (g=="week")
    {
        cout<<a[n-1]<<endl;;
    }
    else
    {
        int ans=0;
        for (int i=0;i<12;i++)
            if (b[i]>=n)
                ans++;
        cout<<ans<<endl;
    }
}