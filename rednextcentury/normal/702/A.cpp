#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=1,cur=0,l=-1;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x>l)cur++;
        else ans=max(ans,cur),cur=1;
        l=x;
    }
    cout<<max(ans,cur)<<endl;
}