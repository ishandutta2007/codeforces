#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
char a[500][500];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k=0,ans=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='[') k++; else k--;
        ans=max(ans,k);
    }
    k=0;
    int n1=0,n2=ans*2+1,p1=1,p2=n2;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='['&&(i==0||s[i-1]==']'))
        {
            n1++;
            for (int j=1; j<=n2; j++)
            if (j<p1||j>p2) {a[n1][j]=' '; a[n1+1][j]=' ';} else
            if (j==p1||j==p2) {a[n1][j]='+'; a[n1+1][j]='-';} else
                {
                    a[n1][j]='|';
                    a[n1+1][j]=' ';
                }
            n1++;
        } else
        if (s[i]=='[')
        {
            p1++;
            p2--;
            for (int j=1; j<=n2; j++)
            if (j<p1||j>p2) { a[n1+1][j]=' ';} else
            if (j==p1||j==p2) {a[n1][j]='+'; a[n1+1][j]='-';} else
                {
                    a[n1][j]='|';
                    a[n1+1][j]=' ';
                }
            n1++;
        } else
        if (s[i-1]=='[')
        {
            n1++;
            n1++;
            for (int j=1; j<=n2; j++)
            {
            if (j<p1||j>p2) {a[n1][j]=' '; a[n1+1][j]=' ';} else
            if (j==p1||j==p2) {a[n1][j]='-'; a[n1+1][j]='+';} else
            {
                a[n1][j]=' ';
                a[n1+1][j]='|';
            }
            a[n1-1][j]=' ';
            }
            n1++;
        } else
        {
            p1--;
            p2++;
            for (int j=1; j<=n2; j++)
            if (j<p1||j>p2) {a[n1][j]=' '; a[n1+1][j]=' ';} else
            if (j==p1||j==p2) {a[n1][j]='-'; a[n1+1][j]='+';} else
            {
                a[n1+1][j]='|';
            }
            n1++;
        }
    }
    for (int j=1; j<=n2; j++)
    {
        for (int i=1; i<=n1; i++)
            cout<<a[i][j];
        cout<<endl;
    }
}