#include <iostream>
#include <string>
using namespace std;
string x;
int cur, N;
int main()
{
    cin>>N;
    cin>>x;
    for(int i=0; i<x.length()-1; i++)
    {
        if(x[i]=='S'&&x[i+1]=='F')
        {
            ++cur;
        }
        if(x[i]=='F'&&x[i+1]=='S')
        {
            --cur;
        }
    }
    if(cur>0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}