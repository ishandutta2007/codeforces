#include <bits/stdc++.h>
using namespace std;
int num[30];
string ans="-1";
int n,m;
int numm[30];
void check(string s)
{
    for (int i=0;i<30;i++)
        numm[i]=num[i];
    for (int i=0;i<26;i++)
        while(numm[i]--)
            s+=char(i+'a');
    if (ans=="-1")
        ans=s;
    else
        ans=min(ans,s);
}
int main()
{
    string a,b;
    cin>>a>>b;
    n=a.length();
    m=b.length();
    string cur="";
    for (int i=0;i<n;i++)
        num[a[i]-'a']++;
    bool p=1;
    for (int i=0;i<min(n,m);i++)
    {
        int j=b[i]-'a';
        j++;
        while(j<26 && num[j]==0)
            j++;
        if (j<26)
        {
            num[j]--;
            check(cur+char(j+'a'));
            num[j]++;
        }
        cur+=b[i];
        num[b[i]-'a']--;
        if (num[b[i]-'a']<0){
            p=0;
            break;
        }
    }
    if (n>m && p){
        check(cur);
        cout<<ans<<endl;
    }
    else
        cout<<ans<<endl;
}