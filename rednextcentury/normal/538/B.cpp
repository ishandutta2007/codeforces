# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int a[1000001];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int mx=0;
    for (int i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
        mx=max(mx,a[i]);
    }
    string cur;
    while(true)
    {
        int sum=0;
        bool p=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]==0 && p==1)
            {
                cur+='0';
            }
            if (a[i]>0)
            {
                p=1;
            }
            if (a[i]>0 && p==1)
            {
                cur+='1';
                a[i]--;
            }
            sum+=a[i];
        }
        if (sum==0)
            break;
        cur+=' ';
    }
    cout<<mx<<endl;
    cout<<cur<<endl;

}