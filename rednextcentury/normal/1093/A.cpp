#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int ret=0;
        if (x%2)ret++,x-=3;
        ret+=x/2;
        cout<<ret<<endl;
    }
}