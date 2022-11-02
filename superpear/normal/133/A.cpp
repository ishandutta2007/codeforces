#include <iostream>
#include <string>

using namespace std;

int main()
{
    int flag=1;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
      if ((s[i]=='H') or (s[i]=='Q') or (s[i]=='9'))
        flag=0;
    if (flag==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    return 0;
}