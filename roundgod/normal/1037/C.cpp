/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 22:41:28
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
int n;
string a,b;
int main()
{
    scanf("%d",&n);
    cin>>a;cin>>b;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i]) 
        {
            if(i!=n-1&&a[i+1]!=b[i+1]&&a[i]!=a[i+1])
            {
                ans++;
                swap(a[i],a[i+1]);
            }
            else ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}