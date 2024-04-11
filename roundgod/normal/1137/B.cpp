#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next fdoiafjds
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
string s,t;
int main()
{
    cin>>s;
    cin>>t;
    int n=t.size();
    int cnt0=0,cnt1=0;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='0') cnt0++; else cnt1++;
    }
    vector<int> next(n+1,0);
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(t[j]==t[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
    int f=0,g=0;
    for(int i=0;i<(int)t.size();i++)
    {
        if(t[i]=='0') f++; else g++; 
    }
    int ff=0,gg=0;
    for(int i=next[n];i<(int)t.size();i++)
    {
        if(t[i]=='0') ff++; else gg++;
    }
    if(cnt0<f||cnt1<g)
    {
        cout<<s<<endl;
        return 0;
    }
    cout<<t;
    cnt0-=f;cnt1-=g;
    while(cnt0>=ff&&cnt1>=gg)
    {
        cout<<t.substr(next[n],n-next[n]);
        cnt0-=ff;
        cnt1-=gg;
    }
    for(int i=0;i<cnt0;i++) cout<<'0';
    for(int i=0;i<cnt1;i++) cout<<'1';
    return 0;
}