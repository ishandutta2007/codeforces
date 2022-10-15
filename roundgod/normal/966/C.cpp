#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll a[MAXN];
vector<ll> res;
ll save[60];
struct trie
{
    trie* next[2];
    ll cnt,cnt2;
};
trie* thead;
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->cnt=0;t->cnt2=0;
    return t;
}
void insert(ll x)
{
    trie* s=thead;
    trie* t;
    ll last=-1;
    for(ll i=0;i<60;i++)
    {
    	save[59-i]=x&1;
    	if(x&1) last=59-i;
    	x=x>>1;
    }
    for(ll i=0;i<60;i++)
    {
        if(s->next[save[i]]) {s=s->next[save[i]]; s->cnt++; if(i==last) s->cnt2++;}
        else
        {
            t=newnode();
            s->next[save[i]]=t;
            s=t;
            s->cnt++;
            if(i==last) s->cnt2++;
        }
    }
    return;
}
ll find(ll x)
{
    trie* s=thead;
    ll ans=0;
    for(ll i=0;i<60;i++)
    {
    	save[59-i]=x&1;
    	x=x>>1;
    }
    ll last=-1;
    for(ll i=0;i<60;i++)
    {
    	if(save[i]==0)
    	{
    		if(s->next[1]&&(s->next[1]->cnt2)>0) last=i;
    		if(s->next[0]&&s->next[0]->cnt) s=s->next[0]; else break;
    	}
    	else
    	{
    		if(s->next[0]==NULL||s->next[0]->cnt==0) break;
    		s=s->next[0];
    	}
    }
    if(last==-1) return -1;
    s=thead;
    for(ll i=0;i<60;i++)
    {
    	if(i<last)
    	{
    		s=s->next[0];
    		ans+=(1LL<<(59-i))*save[i];
    		s->cnt--;
    		s->cnt2--;
    	}
    	if(i==last) {s=s->next[1]; s->cnt--; s->cnt2--; ans+=1LL<<(59-i);}
    	if(i>last)
    	{
    		if(s->next[save[i]]&&s->next[save[i]]->cnt)
    		{
    			s=s->next[save[i]];
    			s->cnt--;
    		}
    		else
    		{
    			s=s->next[1-save[i]];
    			s->cnt--;
    			ans+=1LL<<(59-i);
    		}
    	}
    }
    return ans;
}
void deltrie(trie* s)
{
    ll i;
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
	scanf("%I64d",&n);
	thead=newnode();
	for(ll i=0;i<n;i++) 
	{
		scanf("%I64d",&a[i]);
		insert(a[i]);
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ll now=find(ans);
		if(now==-1)
		{
			puts("No");
			return 0;
		}
		res.push_back(now^ans);
		ans=now;
	}
	puts("Yes");
	for(ll i=0;i<res.size();i++)
		printf("%I64d ",res[i]);
	deltrie(thead);
	return 0;
}