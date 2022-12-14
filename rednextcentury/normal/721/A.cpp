#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ret;
    int n;
    cin>>n;
    int num=0;
    for (int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        if (x=='W')
        {
            if (num>0)
                ret.push_back(num);
            num=0;
        }
        else
            num++;
    }
    if (num>0)
        ret.push_back(num);
        cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<' ';
    }
    cout<<endl;
}