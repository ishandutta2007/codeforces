#include<iostream>

using namespace std;

int main ()
{
    int n;

    cin>>n;

    string s;

    cin>>s;

    bool b=false;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            b=true;
        else
            cnt++;
    }

    if(b==false)
        cout<<"0"<<endl;
    else
    {
        cout<<"1";
        for(int i=0;i<cnt;i++)
            cout<<"0";
        cout<<endl;
    }

    return 0;
}