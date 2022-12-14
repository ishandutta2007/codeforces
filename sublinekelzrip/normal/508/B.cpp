#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int hv[15];
string s;
int main()
{
    cin>>s;
    int n=s.length(),numo=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]%2==0)
        {
            numo=1;
            if(s[i]<s[n-1])
            {
                swap(s[i],s[n-1]);
                cout<<s;
                return 0;
            }
        }
    }
    if(numo==0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]%2==0)
        {
            {
                swap(s[i],s[n-1]);
                cout<<s;
                return 0;
            }
        }
    }   
}