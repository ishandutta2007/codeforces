#include <bits/stdc++.h>
using namespace std;
string fr[]={"Danil", "Olya", "Slava", "Ann","Nikita"};
int main()
{
    string s;
    cin>>s;
    int ret=0;
    for (int i=0;i<s.size();i++)
    {
        for (int j=0;j<5;j++)
        {
            if (s.substr(i,fr[j].size())==fr[j])
                ret++;
        }
    }
    if (ret==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}