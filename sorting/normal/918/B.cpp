#include<iostream>
#include<map>

using namespace std;

map<string,string> mp;

int main ()
{
    int n,m,i;
    string name,ip;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>name>>ip;
        mp[ip]=name;
    }

    for(i=0;i<m;i++)
    {
        cin>>ip>>name;
        name.erase(name.size()-1,1);
        cout<<ip<<" "<<name<<"; #"<<mp[name]<<endl;
    }

    return 0;
}