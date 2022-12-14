#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int num=0;
        int mx1=-1,mx2=-1;
        for (int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if (x>mx1){
                swap(mx1,mx2);
                mx1=x;
            } else if (x>mx2)
            {
                mx2=x;
            }
        }
        cout<<min(mx2-1,n-2)<<endl;
    }
}