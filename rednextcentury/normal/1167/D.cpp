#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int r=0,b=0;
    string ret="";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='(')
        {
            if (r<b)
            {
                r++;
                ret+="1";
            }
            else
            {
                b++;
                ret+="0";
            }
        }
        else
        {
            if (r>b)
            {
                r--;
                ret+="1";
            }
            else
            {
                b--;
                ret+="0";
            }
        }
    }
    cout<<ret<<endl;
}