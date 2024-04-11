#include<bits/stdc++.h>
using namespace std;
vector<int> ret;
int check(int x)
{
    int r=x;
    while(x)
    {
        r+=x%10;
        x/=10;
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=100;i++)
    {
        if (i<n)
        {
            if (check(n-i)==n)
                ret.push_back(n-i);
        }
    }
    sort(ret.begin(),ret.end());
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<endl;
}