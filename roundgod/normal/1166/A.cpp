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
int n,k,a[MAXN];
int cnt[26];
string str;
int get(int x)
{
    return x*(x-1)/2;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        cnt[str[0]-'a']++;
    }
    int ans=0;
    for(int i=0;i<26;i++) ans+=get(cnt[i]/2)+get((cnt[i]+1)/2);
    printf("%d\n",ans);
    return 0;
}