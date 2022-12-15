#include<iostream>

using namespace std;

int main ()
{
    int n,a,b,i,p,c=0,res=0;

    ios::sync_with_stdio(false);

    cin>>n>>a>>b;

    for(i=0;i<n;i++)
    {
        cin>>p;

        if(p==1)
        {
            if(a!=0)
            {
                a--;
            }
            else
            {
                if(b!=0)
                {
                    b--;
                    c++;
                }
                else
                {
                    if(c!=0)c--;
                    else res++;
                }
            }
        }
        else
        {
            if(b!=0)
            {
                b--;
            }
            else res+=2;
        }
    }

    cout<<res<<endl;

    return 0;
}