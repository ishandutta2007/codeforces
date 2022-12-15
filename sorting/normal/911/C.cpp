#include<iostream>

using namespace std;

int  main ()
{
    long long  a,b,c,i,j,j2;

    ios::sync_with_stdio(false);

    cin>>a>>b>>c;


    if(a*b+a*c+b*c<a*b*c)
    {
        cout<<"NO"<<endl;
        return 0;
    }


    if(a<b)swap(b,a);
    if(a<c)swap(c,a);

    for(i=0;i<b;i++)
    {
        for(j=0;j<c;j++)
        {
            for(j2=0;j2<a*b*c;j2++)
            {
                if(j2%a!=0 && j2%b!=i && j2%c!=j)
                {
                    break;
                }
            }

            if(j2==a*b*c)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}