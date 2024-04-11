#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
    {
    int n;
    int i;
    int br=0;
    int br1=0;
    int br2=0;
    int c;
    vector <int> v;
    v.clear();
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&c);
        br2++;
        if(c<0)br++;
        if(br==3){v.push_back(br2-1);br1++;br=1;br2=1;}
        }
    v.push_back(br2);
    br1++;
    printf("%d\n",br1);
    for(i=0;i<v.size();i++)
        {
        printf("%d ",v[i]);
        }
    printf("\n");
    return 0;
    }