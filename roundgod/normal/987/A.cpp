/*************************************************************************
    > File Name: A(2).cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 01:38:42
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
map<string,string> mp;
string str;
int main()
{
    mp["red"]="Reality";
    mp["purple"]="Power";
    mp["green"]="Time";
    mp["blue"]="Space";
    mp["orange"]="Soul";
    mp["yellow"]="Mind";
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        mp[str]="";
    }
    printf("%d\n",6-n);
    for(auto it=mp.begin();it!=mp.end();it++)
        if(it->S!="") cout<<it->S<<endl;
    return 0;
}