#include<bits/stdc++.h>
using namespace std;
bool x[100];
string s[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>s[i];
    int mx=0;
    for (int j=0;j<26;j++)
    {
        for (int i=j+1;i<26;i++)
        {
            int tot=0;
            x[j]=x[i]=1;
            for (int p=0;p<n;p++)
            {
                int k=s[p].length();
                bool is=1;
                for (int h=0;h<k;h++)
                    if (x[s[p][h]-'a']==0) is=0;
                if (is)
                    tot+=k;
            }
            x[j]=x[i]=0;
            mx=max(mx,tot);
        }

    }
    cout<<mx<<endl;
}