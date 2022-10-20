#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    string a;
    cin>>a;
    int n=a.size();
    int i;
    int mx=-1;
    int br=-1;
    for(i=0;i<n;i++)
        {
        if((a[i]-'a')>mx)
            {
            br=1;
            mx=a[i]-'a';
            }
        else if((a[i]-'a')==mx)
            {
            br++;
            }
        }
    for(i=0;i<br;i++)
        {
        cout<<char(mx+'a');
        }
    cout<<"\n";
    return 0;
    }