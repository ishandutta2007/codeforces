#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a[MAXN];
string str;
vector<int> zero,one;
int n,sum[MAXN];
bool check(int x)
{
    if(x==0) return one.back()-one[0]+1==(int)one.size();
    for(int i=0;i<(int)zero.size();i++)
    {
        int last=min(i+x-1,(int)zero.size()-1);
        int l=(i==0?0:zero[i-1]+1),r=(last==zero.size()-1?n-1:zero[last+1]-1);
        if(sum[r]-(l==0?0:sum[l-1])+x>=sum[n-1]) return true;
    }
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        zero.clear(); one.clear(); 
        cin>>str;
        n=(int)str.size();
        for(int i=0;i<n;i++) sum[i]=0;
        for(int i=0;i<n;i++)
            if(str[i]=='0') zero.push_back(i); else {one.push_back(i);sum[i]=1;}
        for(int i=1;i<n;i++) sum[i]+=sum[i-1];
        if(!zero.size()||!one.size()) {puts("0"); continue;}
        int l=-1,r=n;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}