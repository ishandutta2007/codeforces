#include<iostream>
#include<cstdio>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;

bool query(int r1,int c1,int r2,int c2)
{
    cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    fflush(stdout);

    string s;

    cin>>s;

    if(s=="YES")
        return 1;

    return 0;
}

string res,res2;

int main ()
{
    int n,i,x,y;

    cin>>n;

    for(i=n;i>=1;i--)
    {
        if(query(1,1,i,n-i+1))
            if(query(i,n-i+1,n,n))
                break;
    }

    x=1;
    y=1;

    while(x!=i || y!=n-i+1)
    {
        if(query(x+1,y,n,n))
        {
            res+="D";
            x++;
        }
        else
        {
            res+="R";
            y++;
        }
    }

    x=n;
    y=n;

    while(x!=i || y!=n-i+1)
    {
        if(query(1,1,x,y-1))
        {
            res2="R"+res2;
            y--;
        }
        else
        {
            res2="D"+res2;
            x--;
        }
    }

    cout<<"! "<<res<<res2<<endl;
    fflush(stdout);

    return 0;
}