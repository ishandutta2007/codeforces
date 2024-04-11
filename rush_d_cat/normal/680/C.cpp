#include<iostream>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main()
{
    int a[20]={2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47};
    int cnt=0;
    char s[5];
    for(int i=0;i<=18;i++)
    {
        printf("%d\n",a[i]);
        fflush(stdout);
        gets(s);
        if(s[0]=='y'&&s[1]=='e') cnt++;
    }
    if(cnt>=2) cout<<"composite"<<endl;
    else cout<<"prime"<<endl;
    return 0;
}