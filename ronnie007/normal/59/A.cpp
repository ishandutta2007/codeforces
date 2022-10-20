#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    int br1=0;
    int br2=0;
    int n;
    int i,j;
    cin>>a;
    n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]>='a' && a[i]<='z')br1++;
        else br2++;
        }
    if(br1>=br2)
        {
        for(i=0;i<n;i++)
            {
            if(a[i]>='A' && a[i]<='Z')
                {
                a[i]=(a[i]-'A')+'a';
                }
            cout<<a[i];
            }
        }
        else
            {
            for(i=0;i<n;i++)
                {
                if(a[i]>='a' && a[i]<='z')
                    {
                    a[i]=(a[i]-'a')+'A';
                    }
                cout<<a[i];
                }
            }

    cout<<"\n";
    return 0;
    }