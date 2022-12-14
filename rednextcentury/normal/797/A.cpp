#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    vector<int> ret;
    cin>>n>>k;
    int p=k;
    for (int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            if (k>1)
                k--,ret.push_back(i),n/=i;
            else
                break;
        }
    }
    if (n>1)ret.push_back(n);
    if (ret.size()!=p)
    {
        cout<<-1<<endl;
    }
    else
        for (int i=0;i<p;i++)
            cout<<ret[i]<<' ';

}