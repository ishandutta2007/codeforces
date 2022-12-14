#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    int n;
    cin>>n;
    int A=0,B=0;
    for (int i=0;i<n;i++)
    {
        int s;
        cin>>s;
        for (int j=0;j<s/2;j++)
        {
            int x;
            cin>>x;
            A+=x;
        }
        if (s%2)
        {
            int x;
            cin>>x;
            vec.push_back(x);
        }
        for (int j=0;j<s/2;j++)
        {
            int x;
            cin>>x;
            B+=x;
        }
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for (int  i=0;i<vec.size();i++)
    {
        if(i%2)B+=vec[i];
        else A+=vec[i];
    }
    cout<<A<<' '<<B<<endl;
}