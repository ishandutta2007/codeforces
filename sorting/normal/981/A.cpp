#include<iostream>

using namespace std;

string s;

bool check(int x,int y)
{
    int i,mid;
    mid=(x+y)/2;

    for(i=x;i<=mid;i++)
        if(s[i]!=s[y+x-i])
            return 0;
    return 1;
}

int main ()
{
    int i,j,maxi=0,x,y;

    cin>>s;

    for(i=0;i<s.size();i++)
        for(j=i+1;j<s.size();j++)
            if(!check(i,j))
            {
                if(j-i+1>maxi)
                {
                    x=i;
                    y=j;
                    maxi=j-i+1;
                }
            }

    cout<<maxi<<endl;

    return 0;
}