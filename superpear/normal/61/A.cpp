#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

string s1,s2;
int main()
{
    cin>>s1;
    cin>>s2;
    for (int i=0;i<s1.size();i++)
      if (s1[i]==s2[i])
        cout<<"0";
      else
        cout<<"1";
    cout<<endl;
    return 0;
}