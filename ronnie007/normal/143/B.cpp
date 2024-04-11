#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
    {
    string a;
    cin>>a;
    if(a[0]=='-')
        {
        printf("($");
        }
    else
        {
        printf("$");
        }
    int i;
    int br=0;
    int br2=0;
    int n=a.size();
    int br1=0;
    for(i=0;i<n;i++)
        {
        if(a[i]!='.')
            {
            if(a[i]!='-')br++;
            }
        else break;
        }
    br2=br;
    for(i=0;i<n;i++)
        {
        if(a[i]!='-')
            {
            if(br==0)break;
            if(br%3==0 && br!=br2)printf(",");
            br--;
            cout<<a[i];
            }
        }
    cout<<".";
    for(i=n-1;i>=0;i--)
        {
        if(a[i]!='.')
            {
            br1++;
            }
        else break;
        }
    if(br2==n || br2==n-1)br1=0;
    if(a[0]=='-')br2++;
    if(br1==0)
        {
        cout<<"00";
        }
    else if(br1==1)
        {
        cout<<a[n-1]<<"0";
        }
    else
        {
        cout<<a[n-br1]<<a[n-br1+1];
        }
    if(a[0]=='-')printf(")");
    printf("\n");
    return 0;
    }