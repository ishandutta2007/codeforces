
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char cx='.';
    char cy='.';
    int num=1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='U' || s[i]=='D')
        {
            if (cy=='.')
                cy=s[i];
            else if (cy!=s[i])
            {
                num++;
                cy=s[i];
                cx='.';
            }
        }
        else
        {
            if (cx=='.')
                cx=s[i];
            else if (cx!=s[i])
            {
                num++;
                cx=s[i];
                cy='.';
            }
        }
    }
    cout<<num<<endl;
}