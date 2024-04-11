# include <iostream>
# include<algorithm>
#include <stdio.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int mx=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]<t[i])
        {
            bool p=0;
            bool k=0;
            bool j=0;
            if ((int)t[i]-s[i]>1)
                j=1;
            for (int x=i+1;x<n;x++)
            {
                if (t[x]!='a')
                    p=1;
                if (s[x]!='z')
                    k=1;
            }
            if (p)
            {
                s[i]=char(s[i]+1);
                for (int x=0;x<=i;x++)
                    cout<<s[x];
                for (int x=i+1;x<n;x++)
                    cout<<'a';
                cout<<endl;
                return 0;
            }
            if (k)
            {
                for (int x=0;x<=i;x++)
                    cout<<s[x];
                for (int x=i+1;x<n;x++)
                    cout<<'z';
                cout<<endl;
                return 0;
            }
            if (j)
            {

                s[i]=char(s[i]+1);
                cout<<s<<endl;
                return 0;
            }
        }
    }
    cout<<"No such string"<<endl;
}