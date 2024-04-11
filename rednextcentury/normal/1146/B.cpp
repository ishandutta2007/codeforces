
#include<bits/stdc++.h>
#define ll long long
#define NUM 500005

using namespace std;
int a[27];
bool Equal(string t)
{
    ll n=t.size();
    ll j=n/2;
    for(ll i=0; i<n/2; i++)
    {
        if(t[i] != t[j])
            return false;
        j++;
    }
    return true;
}
int main()
{

    string s;
    int A=0;
    cin >> s;
    int l=s.size();
    for(int i=0; i<l; i++)
    {
        if(s[i] == 'a')
            A++;
    }


    if(A == s.size())
    {
        cout << s;
        return 0;
    }

    if(s[l-1] == 'a' && A!=s.size())
    {
        cout << ":(";
        return 0;
    }
    string t="";

    for(int i=0; i<l; i++)
    {
        if(s[i]!='a')
            t+=s[i];
    }


    if(t.size()&1)
    {
        cout << ":(";
        return 0;
    }

    if(!Equal(t))
    {
        cout << ":(";
        return 0;
    }

    int c=0;
    ll n=t.size();
    int i=0;
    bool ok = 0;
    string ret="";
    while(l--)
    {
        if(s[i] !='a'&& c>=n/2)
            ok=1;

        if (ok && s[i]=='a')
        {
            cout<<":("<<endl;
            return 0;
        }


        if(s[i]!='a')
            c++;
        if (!ok)
            ret+=s[i];
        i++;
    }
    cout<<ret<<endl;
}