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
int T,n,m;
string s,t;
int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        cin>>s;
        cin>>t;
        n=(int)s.size(),m=(int)t.size();
        int x=0,y=0;
        bool f=true;
        while(x<n&&y<m)
        {
            char ch=s[x];
            int cnt1=0,cnt2=0;
            while(x<n&&s[x]==ch) x++,cnt1++;
            while(y<m&&t[y]==ch) y++,cnt2++;
            if(cnt1>cnt2) {f=false; break;}
        }
        if(x!=n||y!=m) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}