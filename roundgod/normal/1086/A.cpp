/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-23 21:36:21
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dsif
#define y1 dsajifosd
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
P a[3];
vector<P> ans;
bool cmp(P x,P y)
{
    return x.S<y.S;
}
int main()
{
    scanf("%d%d%d%d%d%d",&a[0].F,&a[0].S,&a[1].F,&a[1].S,&a[2].F,&a[2].S);
    ans.push_back(a[0]);
    ans.push_back(a[1]);
    ans.push_back(a[2]);
    sort(a,a+3);
    while(a[0].F<a[1].F) {a[0].F++; ans.push_back(a[0]);}
     while(a[2].F>a[1].F) {a[2].F--; ans.push_back(a[2]);}
    sort(a,a+3,cmp);
    while(a[0].S<a[1].S) {a[0].S++; ans.push_back(a[0]);}
    while(a[2].S>a[1].S) {a[2].S--; ans.push_back(a[2]);}
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
}