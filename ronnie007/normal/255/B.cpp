#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int n;
string s;

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
    n=s.size();
    }


void solve()
    {
    int i;
    int br1=0;
    int br2=0;
    for(i=0;i<n;i++)
        {
        if(s[i]=='x')br1++;
        else br2++;
        }
    if(br1>br2)
        {
        for(i=0;i<br1-br2;i++)
            {
            cout<<'x';
            }
        }
    else
        {
        for(i=0;i<br2-br1;i++)
            {
            cout<<'y';
            }
        }
    cout<<"\n";
    }