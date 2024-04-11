#include<bits/stdc++.h>
using namespace std;
int ret=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        ret+=p;
        if (i>=n-k && p>x)
            ret-=p-x;
    }
    cout<<ret<<endl;
}