#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

int n,a[100005],one,now,two,isok=1,tot;
bool vis[100005];
int u[100005],v[100005];
int main()
{
    scanf("%d",&n);
    if(n==1){puts("YES");return 0;}
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]==i) one++,now=i;
    if(one>=1){
        puts("YES");
        for(int i=1;i<=n;i++) if(i!=now) printf("%d %d\n",i,now);
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(a[a[i]]==i) now=i;
    if(!now){puts("NO");return 0;}
    u[tot=1]=now,v[tot]=a[now];vis[now]=vis[a[now]]=1;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int j=a[i],tmp=1;u[++tot]=now,v[tot]=j;vis[j]=1;
        while(j!=i){
            j=a[j];tmp++;vis[j]=1;
            if(tmp&1) u[++tot]=now; else u[++tot]=a[now];
            v[tot]=j;
        }
        if(tmp&1){puts("NO");return 0;}
    }
    puts("YES");
    for(int i=1;i<n;i++)
        printf("%d %d\n",u[i],v[i]);
    return 0;
}