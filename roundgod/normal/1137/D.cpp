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
int tot,k;
string str;
void skip()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++) cin>>str;
}
bool meet()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++) cin>>str;
    return (k==2);
}
bool meet2()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++) cin>>str;
    return (k==1);
}
bool process()
{
    puts("next 1 2 3 4 5");tot++;
    fflush(stdout);
    skip();
    puts("next 1 2 3 4 5 6 7 8 9");tot++;
    fflush(stdout);
    return meet();
}
bool go()
{
    puts("next 0 1 2 3 4 5 6 7 8 9");tot++;
    fflush(stdout);
    return meet2();
}
void end()
{
    puts("done");
    exit(0);
}
int main()
{
    while(!process());
    while(!go());
    end();
    return 0;
}