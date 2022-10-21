#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    string a;
    string b[17];
    cin>>a;
    int i,j;
    int ans=0;
    for(i=0;i<10;i++)
        {
        cin>>b[i];
        }
    int n = a.size();
    string t;
    for(i=0;i<n-7;i+=10)
        {
        t.clear();
        for(j=0;j<10;j++)
            {
            t+=a[i+j];
            }
        if(t==b[1])ans=ans*10+1;
        if(t==b[2])ans=ans*10+2;
        if(t==b[3])ans=ans*10+3;
        if(t==b[4])ans=ans*10+4;
        if(t==b[5])ans=ans*10+5;
        if(t==b[6])ans=ans*10+6;
        if(t==b[7])ans=ans*10+7;
        if(t==b[8])ans=ans*10+8;
        if(t==b[9])ans=ans*10+9;

        if(t==b[0])
            {
            ans=ans*10;
            if(ans==0)printf("0");
            }
        }
    printf("%d\n",ans);
    return 0;
    }