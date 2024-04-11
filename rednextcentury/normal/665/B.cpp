#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int cost(int x)
{
    for (int i=0;i<vec.size();i++)
    {
        if (vec[i]==x)
        {
            vec.erase(vec.begin()+i);
            vec.insert(vec.begin(),x);
            return i+1;
        }
    }
}
int main()
{
    int n,k,m;
    cin>>n>>k>>m;

    for (int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            ans+=cost(x);
        }
    }
    cout<<ans<<endl;
}