#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],p[MAXN];
struct trie
{
    trie* next[2];
    int cnt;
};
trie* thead;
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->cnt=0;
    return t;
}
void insert(int num)
{
    int i;
    trie* s=thead;
    trie* t;
    int x[30];
    for(i=29;i>=0;i--)
    {
    	x[i]=num&1;
    	num>>=1;
    }
    for(i=0;i<30;i++)
    {
        if(s->next[x[i]]) {s=s->next[x[i]]; s->cnt++;}
        else
        {
            t=newnode();
            s->next[x[i]]=t;
            t->cnt=1;
            s=t;
        }
    }
    return;
}
int find(int num)
{
    trie* s=thead;
    int i;
    int x[30];
    for(i=29;i>=0;i--)
    {
    	x[i]=num&1;
    	num>>=1;
    }
    for(i=0;i<30;i++)
    {
        if(s->next[x[i]]&&s->next[x[i]]->cnt) {s=s->next[x[i]]; x[i]=0; s->cnt--;}
        else {s=s->next[1-x[i]]; x[i]=1; s->cnt--;}
    }
    int ans=0,d=1;
    for(int i=29;i>=0;i--)
    {
    	if(x[i]) ans+=d;
    	d=d*2;
    }
    return ans;
}
void deltrie(trie* s)
{
    int i;
    for(i=0;i<2;i++)
    {
        if(s->next[i])
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
int main()
{
    thead=newnode();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&p[i]);
    	insert(p[i]);
    }
    for(int i=0;i<n;i++)
    	printf("%d ",find(a[i]));
    deltrie(thead);
    return 0;
}