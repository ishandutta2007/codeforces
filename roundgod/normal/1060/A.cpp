/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 15:03:52
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
string str;
int cnt=0;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
        if(str[i]=='8') cnt++;
    printf("%d\n",min(cnt,n/11));
    return 0;
}