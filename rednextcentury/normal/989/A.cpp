#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    for (int i=0;i+2<s.size();i++)
    {
        string x = s.substr(i,3);
        sort(x.begin(),x.end());
        if (x=="ABC")
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}