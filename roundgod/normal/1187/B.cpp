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
int n,m;
string str;
vector<int> pos[26]; 
int cnt[26];
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++) pos[str[i]-'a'].push_back(i+1);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        cin>>str;
        n=(int)str.size();
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int j=0;j<n;j++) cnt[str[j]-'a']++;
        for(int j=0;j<26;j++) if(cnt[j]) ans=max(ans,pos[j][cnt[j]-1]);
        printf("%d\n",ans);
    }
    return 0;
}