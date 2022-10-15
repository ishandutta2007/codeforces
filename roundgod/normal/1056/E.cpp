/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 17:01:40
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define BASE 19260817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int n,m,cnt0,cnt1,cnt,ncnt,ans;
int pre[MAXN],p[MAXN];
int fst,nfst;
int main()
{
    cin>>s;
    cin>>t;
    n=(int)s.size();m=(int)t.size();
    p[0]=1;
    for(int i=1;i<=1000000;i++) p[i]=1LL*BASE*p[i-1]%MOD;
    cnt0=cnt1=0;
    for(int i=0;i<n;i++) if(s[i]=='0') cnt0++; else cnt1++;
    pre[0]=0;
    for(int i=1;i<=m;i++) pre[i]=(1LL*BASE*pre[i-1]+(t[i-1]-'a'+1))%MOD;
    char ch;
    if(cnt0>cnt1) 
    {
        cnt=cnt0;ncnt=n-cnt0;
        ch='0';
    }
    else 
    {
        cnt=cnt1;ncnt=n-cnt1;
        ch='1';
    }
    ans=0;
    for(int i=1;i*cnt<m;i++)
    {
        if((m-i*cnt)%ncnt!=0) continue;
        int len1=i,len2=(m-i*cnt)/ncnt;
        int cur=0,hsh=0;
        int val1=-1,val2=-1;
        bool f=true;
        for(int j=0;j<n;j++)
        {
            if(s[j]==ch)
            {
                int last=cur+len1;
                int newval=(pre[last]-1LL*pre[cur]*p[len1])%MOD;
                if(newval<0) newval+=MOD;
                hsh=(1LL*hsh*p[len1]+newval)%MOD;
                if(val1==-1) {val1=newval;}
                else if(val1!=newval) {f=false; break;}
                if(hsh<0) hsh+=MOD;
                cur=last;
            }
            else
            {
                int last=cur+len2;
                int newval=(pre[last]-1LL*pre[cur]*p[len2])%MOD;
                if(newval<0) newval+=MOD;
                if(val2==-1) {val2=newval;}
                else if(val2!=newval) {f=false; break;}
                hsh=(1LL*hsh*p[len2]+newval)%MOD;
                if(hsh<0) hsh+=MOD;
                cur=last;
            }
        }
        if(f&&(val1!=val2||len1!=len2)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}