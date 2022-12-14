# include <iostream>
# include <map>
using namespace std;
map<string,int> mp;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ++mp[s];
    }
    map<string,int>::iterator it1=mp.begin();
    map<string,int>::iterator it2=mp.begin();it2++;
    if (it2==mp.end())
        cout<<it1->first<<endl;
    else
    {
        if (it1->second>it2->second)
            cout<<it1->first<<endl;
        else
            cout<<it2->first<<endl;
    }
}