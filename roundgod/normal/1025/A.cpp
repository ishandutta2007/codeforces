/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 21:34:44
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
int n,k,a[26];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    if(n==1) {puts("Yes"); return 0;}
    for(int i=0;i<n;i++) a[str[i]-'a']++;
    for(int i=0;i<26;i++)
        if(a[i]>=2) {puts("Yes"); return 0;}
    puts("No");
    return 0;
}