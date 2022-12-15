#include<iostream>

using namespace std;

int a[26];

int main ()
{
    string s;
    int i,l,k,p=0;

    cin>>s>>k;

    l=s.size();

    for(i=0;i<l;i++)
    {
        if(a[s[i]-'a']==0)p++;
        a[s[i]-'a']++;
    }

    if(l<k)cout<<"impossible"<<endl;
    else
    {
        if(p>=k)cout<<"0"<<endl;
        else cout<<k-p<<endl;
    }

    return 0;
}