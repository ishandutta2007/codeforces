/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 22:34:53
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
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n-1;i++)
        if(str[i]!=str[i+1])
        {
            puts("YES");
            cout<<str.substr(i,2)<<endl;
            return 0;
        }
    puts("NO");
    return 0;
}