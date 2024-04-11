# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
int seven=0,four=0;
int n;
void print2()
{
    for (int i=0;i<n/2+1;i++)
        cout<<'4';
    for (int i=0;i<n/2+1;i++)
        cout<<'7';
    cout<<endl;
}
    string s;
void print(int i)
{
    for (int x=0;x<i;x++)
        cout<<s[x];
    for (;i<n;i++)
    {
        if (four<n/2)
        {
            cout<<'4';
            four++;
        }
        else
            cout<<'7';
    }
    cout<<endl;
}
int main()
{
    cin>>s;
    n=s.length();
    int l1=-1,l2=-1;
    if (n%2!=0)
    {
        print2();
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (four<n/2 && s[i]=='4')
            four++,l1=i;
        else if (seven<n/2 && s[i]=='7')
            seven++,l2=i;
        else
        {
            for (int x=i;x>=0;x--)
            {
                if (s[x]<'4')
                {
                    if (four==n/2)
                    {
                        s[x]='7';
                        seven++;
                        print(x+1);
                        return 0;
                    }
                    else
                    {
                        s[x]='4';
                        four++;
                        print(x+1);
                        return 0;
                    }
                }
                else if (s[x]=='4')
                {
                    if (seven<n/2)
                    {
                        s[x]='7';
                        four--;
                        seven++;
                        print(x+1);
                        return 0;
                    }
                }
                else if (s[x]<'7')
                {
                    if (seven<n/2)
                    {
                        s[x]='7';
                        seven++;
                        print(x+1);
                        return 0;
                    }
                }
                if (s[x]=='4' && i!=x)
                    four--;
                if (s[x]=='7' && i!=x)
                    seven--;
            }
            print2();
            return 0;
        }
    }
    cout<<s<<endl;
}