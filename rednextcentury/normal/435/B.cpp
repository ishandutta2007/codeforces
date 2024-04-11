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
int main()
{
    string s;int k;
    cin>>s>>k;
    int n=s.length();
    int nowx=0;
    while (k>0)
    {
        if (nowx==n-1)
            break;
        int dist=0;
        int best='0';
        for (int i=nowx+1;i<n;i++)
        {
            if (s[i]>s[nowx] && s[i]>best && i-nowx<=k)
            {
                best=s[i];
                dist=i;
            }
        }
        if (dist>0)
        {
        k-=dist-nowx;
        int h=dist;
        char t=s[dist];
        while(s[nowx]!=t)
        {
            swap(s[h],s[h-1]);
            h--;
        }
        }
        nowx++;
    }
    cout<<s<<endl;
}