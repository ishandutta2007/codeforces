#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;



int i,n;
string a;
string b;


void input();
void solve();




int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
    cin>>a;
    n=a.size();
    }


void solve()
    {
    int i;
    int fl=0;
    for(i=0;i<n;i++)
        {
        if(a[i]=='0' && fl==0)fl=1;
        else
            {
            if(i<n-1 || fl==1)b+=a[i];
            }
        }
    cout<<b<<"\n";
    }