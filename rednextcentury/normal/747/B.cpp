#include<bits/stdc++.h>
using namespace std;
int a[1000];
char b[]={'A','C','T','G'};
int main()
{
    int n;
    string s;
    cin>>n>>s;
    if (n%4)
    {
        cout<<"===\n";
        return 0;
    }
    else
    {
        int need=n/4;
        for (int i=0;i<n;i++)
        {
            a[s[i]]++;
            if (s[i]!='?' && a[s[i]]>need)
            {
                cout<<"===\n";
                return 0;
            }
        }
        for (int i=0;i<n;i++)
        {
            if  (s[i]=='?')
            {
                for (int j=0;j<4;j++)
                {
                    if (a[b[j]]<need)
                    {
                        a[b[j]]++;
                        s[i]=b[j];
                        break;                    }
                }
            }
        }
        cout<<s<<endl;
    }
}