/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 22:38:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string s,t;
vector<int> ans;
int main()
{
    scanf("%d",&n);cin>>s;cin>>t;
    int now=0;
    while(now<n)
    {
        int id=-1;
        for(int j=now;j<n;j++) if(s[j]==t[now]) {id=j; break;}
        if(id==-1) {puts("-1"); return 0;}
        for(int j=id;j>now;j--)
        {
            ans.push_back(j);
            swap(s[j],s[j-1]);
        }
        now++;
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}