#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


string a;

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
    cin>>a;
    }


void solve()
    {
    if(a[0]>='a' && a[0]<='z')a[0]=(a[0]-'a')+'A';
    cout<<a<<"\n";
    }