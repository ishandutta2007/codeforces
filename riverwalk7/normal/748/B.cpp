#include <iostream>
#include <string>
using namespace std;
string s, t;
int a[1100];
int b[1100];
int c[30];
int main()
{
    cin>>s>>t;
    for(int i=0; i<30; i++)
    {
        c[i]=i;
    }
    for(int i=0; i<s.length(); i++)
    {
        a[i]=s[i]-'a';
        b[i]=t[i]-'a';
        if(a[i]!=b[i])
        {
            if((c[a[i]]!=b[i]&&c[a[i]]!=a[i])||(c[b[i]]!=a[i]&&c[b[i]]!=b[i])) //if a is not fixed and not already mapped to b
            {
                cout<<-1<<endl;
                return 0;
            }
            c[a[i]]=b[i];
            c[b[i]]=a[i];
        }
    }
    for(int i=0; i<s.length(); i++)
    {
        if(c[a[i]]!=b[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int ans=0;
    for(int i=0; i<26; i++)
    {
        if(c[i]>i)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    char x, y;
    for(int i=0; i<26; i++)
    {
        x=i+'a';
        y=c[i]+'a';
        if(i<c[i])
            cout<<x<<" "<<y<<endl;
    }
}