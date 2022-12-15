#include<iostream>

using namespace std;

string s;

int main ()
{
    long long n,i,j,res=0,u,d;

    cin>>s;

    n=s.size();

    for(i=0;i<n;i++)
    {
        u=0;
        d=0;

        for(j=i;j<n;j++)
        {
            if(s[j]=='(')
            {
                u++;
                d++;
            }
            if(s[j]==')')
            {
                if(d==0)
                {
                    if(u==0)break;
                    d=1;
                    u--;
                }
                else
                {
                    d--;
                    u--;
                }
            }
            if(s[j]=='?')
            {
                if(d==0)d=1;
                else d--;
                u++;
            }

            if(d==0)res++;
        }
    }

    cout<<res<<endl;

    return 0;
}