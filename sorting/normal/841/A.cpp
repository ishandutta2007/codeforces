#include<iostream>

using namespace std;

int a[26];

int main ()
{
    string s;
    int n,k,i;

    cin>>n>>k>>s;

    for(i=0;i<n;i++)
    {
        a[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]>k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}