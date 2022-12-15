#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string s;
    int l,i;

    cin>>s;
    l=s.size();

    for(i=0;i<l;i++)
    {
        if(s[i]=='0')
        {
            s.erase(i,1);
            cout<<s<<endl;
            return 0;
        }
    }

    s.erase(0,1);

    cout<<s<<endl;

    return 0;
}