#include<iostream>

using namespace std;

int a[26];

int main ()
{
    string s;
    int l=0,r=0;

    cin>>s;

    int i,n=s.size();

    for(i=0;i<n;i++)
        a[s[i]-'a']++;

    for(i=0;i<26;i++)
    {
        if(a[i])
        {
            l++;
            r++;
            if(a[i]>=2)r++;
        }
    }

    if(l<=4 && r>=4)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}