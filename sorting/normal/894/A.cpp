#include<iostream>

using namespace std;

int main ()
{
    string s;

    cin>>s;

    int l=s.size(),i,q=0,a=0,res=0;

    for(i=0;i<l;i++)
    {
        if(s[i]=='Q')
        {
            res+=a;
            q++;
        }
        else
        {
            if(s[i]=='A')
                a+=q;
        }
    }

    cout<<res<<endl;

    return 0;
}