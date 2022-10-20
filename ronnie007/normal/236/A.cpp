#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
    {
    string a;
    int n;
    int i;
    int used[50];
    for(i=0;i<50;i++)
        {
        used[i]=0;
        }
    cin>>a;
    n=a.size();
    for(i=0;i<n;i++)
        {
        used[(a[i]-'a')]++;
        }
    int br=0;
    for(i=0;i<50;i++)
        {
        if(used[i]!=0)br++;
        }
    if(br%2==1)printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");
    return 0;
    }