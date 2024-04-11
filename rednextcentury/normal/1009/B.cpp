#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
string s,ret;
int main ()
{
   cin>>s;
   for (int i=0;i<s.size();i++)
   {
       if (s[i]=='1')continue;
       ret+=s[i];
   }
   int num=s.size()-ret.size();
    for (int i=0;i<ret.size();i++)
    {
        if (ret[i]=='2')
        {
            while(num>0)
            {
                cout<<"1";
                num--;
            }
        }
        cout<<ret[i];
    }
    while(num>0)cout<<"1",num--;
    cout<<endl;
}