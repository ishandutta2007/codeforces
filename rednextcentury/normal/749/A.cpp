#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> ret;
    cin>>n;
    if (n%2)
        n-=3,ret.push_back(3);
    while(n)
        n-=2,ret.push_back(2);
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<' ';
    }
    cout<<endl;
}