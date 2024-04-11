#include <iostream>
#include <string>

#include <math.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    
    for(int i=0;i<l;i++)
        if(s[i]=='l')
            continue;
        else
            cout<<i+1<<endl;
    
    for(int i=l-1;i>-1;i--)
        if(s[i]=='r')
            continue;
        else
            cout<<i+1<<endl;



    return 0;
}