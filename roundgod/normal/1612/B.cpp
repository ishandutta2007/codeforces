#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        vector<int> leftonly,rightonly,both;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(i==a) leftonly.push_back(i);
            else if(i==b) rightonly.push_back(i);
            else if(i<a&&i>b) f=false;
            else if(i<a) rightonly.push_back(i); 
            else if(i>b) leftonly.push_back(i);
            else both.push_back(i);
        }
        if(leftonly.size()>n/2||rightonly.size()>n/2) f=false;
        if(!f) {puts("-1"); continue;}
        while(leftonly.size()<n/2) leftonly.push_back(both.back()),both.pop_back();
        while(rightonly.size()<n/2) rightonly.push_back(both.back()),both.pop_back();
        for(auto x:leftonly) printf("%d ",x);
        for(auto x:rightonly) printf("%d ",x);
        puts("");
    }
    return 0;
}