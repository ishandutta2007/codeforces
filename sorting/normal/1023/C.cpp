#include<iostream>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;

int curr=0,l=0,r=0;
string res;

int main ()
{
    int n,k,i;
    string s;

    cin>>n>>k;

    cin>>s;

    for(i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            if(l<k/2)
            {
                res+=s[i];
                l++;
                curr++;
            }
        }
        else
        {
            if(r<k/2 && curr>0)
            {
                res+=s[i];
                r++;
                curr--;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}