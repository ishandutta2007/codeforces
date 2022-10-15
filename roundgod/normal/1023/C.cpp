/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 22:43:57
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
vector<P> v;
int st[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(') {st[t++]=i; }
        else 
        {
            v.push_back(P(st[t-1],0));
            v.push_back(P(i,1));
            t--;
            k-=2;
            if(k==0) break;
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i++)
        if(v[i].S==0) printf("("); else printf(")");
    return 0;
}