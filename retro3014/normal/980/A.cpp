#include <iostream>
#include <string>

using namespace std;

string str;

int N, M;

int main()
{
    cin>>str;
    for(int i=0; i<str.size(); i++)
    {
        if(str.at(i)=='-')
        {
            N++;
        }
        else
        {
            M++;
        }
    }
    if(M==0)
    {
        cout<<"YES";
    }
    else if(N%M==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}