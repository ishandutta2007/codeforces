#include<bits/stdc++.h>

using namespace std;
int ret[5001][5001];
char x[10000];
int main()
{
    string s;
    scanf("%s",&x);
    s=x;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        int st=i,en=i;
        while(st>=0 && en<n)
        {
            if (s[st]!=s[en])
                break;
            ret[st][en]++;
            st--,en++;
        }
        if (i==0)
            continue;
        st=i-1,en=i;
        while(st>=0 && en<n)
        {
            if (s[st]!=s[en])
                break;
            ret[st][en]++;
            st--,en++;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            ret[i][j]+=ret[i][j-1];
        }
    }
    for (int j=0;j<n;j++)
    {
        for (int i=j;i>=0;i--)
        {
            ret[i][j]+=ret[i+1][j];
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",ret[l-1][r-1]);
    }
}