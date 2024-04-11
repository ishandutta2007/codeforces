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
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n;
string str;
int cnt[MAXN];
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<n;i++) cnt[i]=(i==0?0:cnt[i-1])+(str[i]=='a');
    int l=0,r=n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(mid+1+(mid+1-cnt[mid])<=n) l=mid; else r=mid;
    }
    if(l+1+l+1-cnt[l]==n)
    {
        string s=str.substr(0,l+1),t="";
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]!='a') t+=s[i];
        }
        if(s+t==str) cout<<s<<endl; else cout<<":("<<endl;
    }
    else cout<<":("<<endl;
    return 0;
}