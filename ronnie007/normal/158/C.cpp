#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

    string a,b;
    string c;
    string last;

int main()
    {
    int n;
    int i,j;
    string dir[1000];
    int br=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        cin>>a;
        if(a[0]=='p')
            {
            cout<<'/';
            for(j=0;j<br;j++)
                {
                cout<<dir[j];
                cout<<'/';
                }
            cout<<"\n";
            }
        else
            {
            cin>>b;
            c.clear();
            if(b[0]=='/')
                {
                br=0;
                dir[0].clear();
                }
            for(j=0;j<b.size();j++)
                {
                if(b[j]!='/')
                    {
                    c+=b[j];
                    }
                else if(b[j]=='/' && j!=0)
                    {
                    if(c[1]=='.')
                        {
                        br--;
                        }
                    else
                        {
                        dir[br]=c;
                        br++;
                        }
                    c.clear();
                    }
                }
            if(c.size()!=0)
                {
                if(c[1]!='.')
                    {
                    dir[br]=c;
                    br++;
                    }
                else
                    {
                    br--;
                    }
                c.clear();
                }
            }
        }
    return 0;
    }