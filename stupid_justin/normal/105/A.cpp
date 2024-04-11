#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    double k,x;
    string s;
    map<string,int> mp;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s>>x;
        x*=k;
        if(x>=100) mp[s]=int(x+1e-6);
    }
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(!mp[s]) mp[s]=0;
    }
    cout<<mp.size()<<endl;
    for(auto c:mp)
        cout<<c.first<<" "<<c.second<<endl;
    return 0;
}