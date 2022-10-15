/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 16:19:28
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
bool cmp(string x,string y)
{
    return x.size()<y.size();
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>str[i];
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(str[j].find(str[i])==-1)
            {
                puts("NO");
                return 0;
            }
    puts("YES");
    for(int i=0;i<n;i++)
        cout<<str[i]<<endl;
    return 0;
}