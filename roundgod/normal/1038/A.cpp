/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 23:35:08
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
string str;
int cnt[26];
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    for(int i=0;i<n;i++)
        cnt[str[i]-'A']++;
    int res=INF;
    for(int i=0;i<k;i++) res=min(res,cnt[i]);
    printf("%d\n",res*k);
    return 0;
}