#include<iostream>

using namespace std;

int main ()
{
    string s;
    int n,i;

    cin>>s;

    n=s.size();

    for(i=1;i<n-1;i++)
    {
        if(s[i]!='.' && s[i-1]!='.' && s[i+1]!='.' && s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;

    return 0;
}