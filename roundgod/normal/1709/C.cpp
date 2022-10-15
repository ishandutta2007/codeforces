#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        int l=0,r=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(') l++;
            else if(str[i]==')') r++;
        }
        int q=(n-(l+r)); 
        if(!q) {puts("YES"); continue;}
        int nl=(q-(l-r))/2,tot=0;
        if(nl==q||nl==0) {puts("YES"); continue;}
        for(int i=0;i<n;i++)
        {
            if(str[i]=='?')
            {
                tot++;
                if(tot==nl)
                {
                    str[i]=')';
                }
                else if(tot==nl+1) {str[i]='(';}
                else if(tot<nl) str[i]='(';
                else str[i]=')';
            }
        }
        bool f=true;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(') cnt++; else cnt--;
            if(cnt<0) f=false;
        }
        if(!f) puts("YES"); else puts("NO");
    }
    return 0;
}