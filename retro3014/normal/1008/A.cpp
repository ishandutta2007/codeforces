#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str;

bool chk(int x)
{
    if(x==str.size())
    {
        return false;
    }
    return (str.at(x)=='a'||str.at(x)=='e'||str.at(x)=='i' || str.at(x)=='o'||str.at(x)=='u');
}

int main()
{
    cin>>str;
    for(int i=0; i<str.size(); i++)
    {
        if(str.at(i)!='n' && !chk(i) && !chk(i+1))
        {
            cout<<"NO";
            return 0;
        }
 
    }
    cout<<"YES";
    return 0;
}