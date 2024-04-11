#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
int main()
{
    long long n;
    cin>>n;
    long long need = n*(n+1)/2;
    cout<<need%2<<endl;
    need/=2;
    for (int i=n;i>=1;i--)
    {
        if (need>=i)
        {
            ret.push_back(i);
            need-=i;
        }
    }
    cout<<ret.size()<<' ';
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';
}