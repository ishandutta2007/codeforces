#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n > 0)
    {
        return n%10 + sum(n/10);
    }
}
vector<int> ans;
int main()
{
    int x;
    cin>>x;
    for(int i=x-100; i<=x; i++)
    {
        if(i > 0 && (i+sum(i)==x))
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    if(!ans.empty())
    {
        for(int i=0; i<ans.size()-1; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[ans.size()-1]<<endl;
    }
}