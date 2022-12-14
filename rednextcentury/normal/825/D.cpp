#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    string s,t;
    ll a[26],b[26],c[26];
    cin >>s>>t;
    for (ll i =0 ; i <26 ; i++)
    {
        a[i] =0 ;
        b[i]=0;
        c[i]=0;
    }
    if (s.length() <t.length())
    {
        for (ll i =0 ; i <s.length() ; i++)
        {
            if (s[i] =='?')
                s[i]=t[i];

        }
    }
    else
    {
        for (ll i = 0 ; i <t.size() ; i++)
        {
            a[t[i]-'a']++;
            // cout <<t[i]-'a'<<" ";
        }
        for (ll i =0 ; i <s.size() ; i++)
        {
            if (s[i] != '?')
            {
                b[s[i]-'a']++;
                c[s[i]-'a']++;
            }

        }
        for (ll i =0 ; i <s.size() ; i++)
        {
            if (s[i] =='?')
            {
                for (ll j =0 ; j<26 ; j++)
                {
                    if (a[j]>0 && b[j]<a[j])
                    {
                        s[i] = 'a'+j;
                        b[j]++;
                        break;
                    }
                }
            }
            ll mn = 10000000;
            for (ll i =0 ; i <26; i++)
                if (a[i]!=0)
                    mn=min(mn,b[i]/a[i]);

            if (s[i] =='?')
            {
                for (ll j =0 ; j<26 ; j++)
                {
                    if (b[j]!=0)
                    {
                        b[j]-=(mn*a[j]);
                    }
                    c[j]=b[j];
                }

            }
            if (s[i] =='?')
            {
                for (ll j =0 ; j<26 ; j++)
                {
                    if (a[j]>0 && b[j]<a[j])
                    {
                        s[i] = 'a'+j;
                        b[j]++;
                        break;
                    }
                }
            }
        }

    }


    cout <<s<<endl;



    return 0;
}