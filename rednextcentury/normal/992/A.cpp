#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> s;
    int z=0;
    while(n--)
    {
        int x;
        cin>>x;
        if (x==0)z=1;
        s.insert(x);
    }
    int ret = s.size();
    cout<<s.size()-z<<endl;
}