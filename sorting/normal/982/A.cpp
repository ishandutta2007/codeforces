#include<iostream>

using namespace std;

int main ()
{
    int n,i,pr,maxi=0;

    cin>>n;

    string s;

    cin>>s;

    pr=-2;

    for(i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            if(i-pr-1==0)
            {
                cout<<"No"<<endl;
                return 0;
            }
            maxi=max(maxi,i-pr-1);
            pr=i;
        }
    }

    if(s.size()-pr-1>=2)
    {
        cout<<"No"<<endl;
        return 0;
    }

    if(maxi<3)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}