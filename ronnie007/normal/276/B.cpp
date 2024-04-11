#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



#define WIN 1
#define LOSE 0


void input();
int dfs(string state);




int main()
    {
    input();
    return 0;
    }


void input()
    {
    string a;
    cin>>a;
    if(dfs(a)==WIN)printf("First\n");
    else printf("Second");
    }



int dfs(string state)
    {
    int br=0;
    int br1=0;
    int n=state.size();
    int i,j;
    int x[1050];
    for(i=0;i<n;i++)
        {
        x[i]=state[i]-'a';
        }
    sort(x,x+n);
    br=1;
    br1=0;
    for(i=1;i<n;i++)
        {
        if(x[i]==x[i-1])br++;
        else
            {
            if(br%2==1){br1++;}
            br=1;
            }
        }
    if(br%2==1){br1++;}
    if((br1==1 || br1==0) || br1%2==1)return WIN;
    return LOSE;
    }