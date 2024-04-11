#include<iostream>
#include<map>

using namespace std;

map<string,bool> mp;

int main ()
{
    int n;

    cin>>n;

    string s;

    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(mp[s])cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
            mp[s]=1;
        }
    }

    return 0;
}