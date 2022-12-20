#include<iostream>

using namespace std;

int main ()
{
    int n,p,i;
    string s;
    bool b=false;

    cin>>n>>p>>s;

    for(i=0;i<n-p;i++)
    {
        if(s[i]=='.' || s[i+p]=='.')
        {
            b=true;
            if(s[i]=='.' && s[i+p]=='.')
            {
                s[i]='1';
                s[i+p]='0';
            }
            else
            {
                if(s[i]=='.')
                {
                    if(s[i+p]=='0')
                        s[i]='1';
                    else
                        s[i]='0';
                }
                else
                {
                    if(s[i]=='0')
                        s[i+p]='1';
                    else
                        s[i+p]='0';
                }
            }
            break;
        }
        if(s[i]!=s[i+p])
        {
            b=true;
            break;
        }
    }

    for(i=0;i<n;i++)
        if(s[i]=='.')
            s[i]='1';

    if(b)
        cout<<s<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}