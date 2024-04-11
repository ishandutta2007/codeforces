#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int x = k;
    for (int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        x = __gcd(x,y);
    }
    vector<int> ret;
    for (int i=0;i<k;i++)
    {
        if (i%x==0)
        {
            ret.push_back(i);
        }
    }
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}