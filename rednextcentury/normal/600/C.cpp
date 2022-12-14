//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
string res[28];
int num[28];
int c[28];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++)
        num[s[i]-'a']++;
    int x=0;
    for (int i=0;i<26;i++)
    {
        if (num[i]%2!=0)
        {
            x++;
        }
    }
    num[26]=1;
    for (int i=0;i<27;i++)
    {
        int m=0;
        if (num[i]%2==0)
        {
            string h;
            for (int j=0;j<=n;j++) h+="z";
            res[i]=h;
            continue;
        }
        for (int j=0;j<26;j++)
            c[j]=num[j];
        for (int j=0;j<26;j++)
        {
            if (num[j]%2==0 || i==j)continue;
            m++;
            if (m<=x/2)
                c[j]++;
            else
                c[j]--;
        }
        string r;
        for (int j=0;j<26;j++)
        {
            for (int k=0;k<c[j]/2;k++)
            {
                r+=j+'a';
            }
        }
        res[i]=r;
        reverse(r.begin(),r.end());
        if (x%2!=0)
            res[i]+=i+'a';
        res[i]+=r;
    }
    sort(res,res+27);
    cout<<res[0]<<endl;
}