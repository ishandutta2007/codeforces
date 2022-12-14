# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
long long finish[2000];
long long start[2000];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    for (int k=0;k<n;k++)
    {
        int j=k;
        int i=k;
        while (i<n && j>=0 && s[i]==s[j])
        {
            i++,j--;
        start[j+1]++;
        finish[i-1]++;
        }
        if (k>0 && s[k]==s[k-1])
        {
            j=k-1;
            i=k;
            while (i<n && j>=0 && s[i]==s[j])
            {
                i++,j--;
            start[j+1]++;
            finish[i-1]++;
            }
        }
    }
    for (int i=n-2;i>=0;i--)
    {
        start[i]+=start[i+1];
    }
    long long ans=0;
    for (int i=0;i<n-1;i++)
    {
        ans+=finish[i]*start[i+1];
    }
    cout<<ans<<endl;
}