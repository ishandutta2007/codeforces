#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

string s,t;

void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin>>s;
    cin>>t;
    }


void solve()
    {
    int n=t.size();
    int i=0;
    int j=0;
    for(j=0;j<n;j++)
        {
        if(s[i]==t[j])i++;
        }
    printf("%d\n",i+1);
    }