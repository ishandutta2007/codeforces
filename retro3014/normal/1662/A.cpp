#include<iostream>
#include<map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            mp[b]=max(mp[b],a);
        }
        long long sm=0;
        for(auto t:mp)
            sm+=t.second;
        if(mp.size()==10)
            cout<<sm<<endl;
        else
            cout<<"MOREPROBLEMS"<<endl;
    }
}