#include<bits/stdc++.h>
using namespace std;
int x[2000000];
int main()
{
    string s;
    cin>>s;
    int i=0;
    while(i<s.size() && s[i]=='a')i++;
    if (i==s.size())s[s.size()-1]='z',cout<<s<<endl;
    else
    {
        int j=i;
        while(j<s.size() && s[j]>'a')
            j++;
        for (int x=i;x<j;x++)
            s[x]--;
        cout<<s<<endl;
    }
}