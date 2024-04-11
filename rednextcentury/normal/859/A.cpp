# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mx=max(mx,x);
    }
    cout<<max(0,mx-25)<<endl;
}