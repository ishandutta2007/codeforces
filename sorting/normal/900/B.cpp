#include<iostream>
#include<map>

using namespace std;

bool mp[10][100001];

int main ()
{
    int a,b,c,i=1,d;

    cin>>a>>b>>c;

    a=a%b;

    while(true)
    {
        if(a==0)
        {
            if(c==0)
            {
                cout<<i<<endl;
                return 0;
            }
            cout<<"-1"<<endl;
            return 0;
        }
        a=a*10;

        d=a/b;
        if(d==c)
        {
            cout<<i<<endl;
            return 0;
        }
        a=a%b;
        if(mp[d][a])
        {
            cout<<"-1"<<endl;
            return 0;
        }
        mp[d][a]=1;
        i++;
    }

    cout<<"-1"<<endl;

    return 0;
}