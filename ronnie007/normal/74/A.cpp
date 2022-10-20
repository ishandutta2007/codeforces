#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int best=-100000;
    string bestname;
    string name;
    int plus;
    int minus;
    int a,b,c,d,e;
    int n;
    int i;
    int x;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>name;
        cin>>plus>>minus;
        cin>>a>>b>>c>>d>>e;
        x=a+b+c+d+e+100*plus-50*minus;
        if(x>best)
            {
            best=x;
            bestname=name;
            }
        }
    cout<<bestname<<"\n";
    return 0;
    }