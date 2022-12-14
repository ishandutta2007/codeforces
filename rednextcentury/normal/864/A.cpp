#include<bits/stdc++.h>
using namespace std;
set<int> s;
int mp[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        s.insert(x);
    }
    if (s.size()==2 && mp[*s.begin()]==n/2 && n%2==0)
        cout<<"YES"<<endl<<*s.begin()<<' '<<*(--s.end())<<endl;
    else cout<<"NO"<<endl;
}