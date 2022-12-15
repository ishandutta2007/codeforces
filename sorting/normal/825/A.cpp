#include<iostream>

using namespace std;

int main ()
{
    int n,i,res=0;
    int x=0;
    string s;

    cin>>n>>s;

    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            res=res*10+x;
            x=0;
        }
        else
        {
            x++;
        }
    }

    res=res*10+x;
    x=0;

    cout<<res<<endl;

    return 0;
}