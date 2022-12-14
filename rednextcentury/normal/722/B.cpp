#include <bits/stdc++.h>
using namespace std;
int p[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>p[i];
    for (int i=0;i<n;i++)
    {
        string s="";
        while(s.length()==0)getline(cin,s);
        for (int j=0;j<s.size();j++)
            if (s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='u' || s[j]=='o' || s[j]=='y')
                p[i]--;
        if (p[i]!=0)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES"<<endl;
}