#include<iostream>

using namespace std;

int a[26];

int main ()
{
    int n,i;
    string s;

    cin>>n>>s;

    if(n==1)
    {cout<<"Yes"<<endl;
            return 0;
    }

    for(i=0;i<n;i++)
        a[s[i]-'a']++;


    for(i=0;i<26;i++)
    {
        if(a[i]>=2)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;

    return 0;
}