// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,MAX=2e6+10,mod=1e9+7;

int par[MAX],cnt[MAX],mx[MAX];
vector<int>vec;
queue<int>q;
int on,ans=1;

int main(){
    for(int i=2;i<MAX;i++){
	if(par[i]==0)
	    for(int j=i;j<MAX;j+=i)
		par[j]=i;
    }
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	int x;scanf("%d",&x);
	cnt[x]++;
    }
    for(int i=2;i<MAX;i++){
	on|=(cnt[i]>2);
	if(cnt[i]>1){
	    q.push(i);
	    q.push(i-1);
	    cnt[i]=0;
	}
    }
    while(sz(q)){
	int x=q.front();
	q.pop();
	vec.clear();
	bool added=0;
	while(x>1){
	    int cn=0,p=par[x];
	    while(x%p==0)
		x/=p,cn++;
	    if(mx[p]==0 && cnt[p]==1)
		cnt[p]=0,q.push(p-1);
	    if(cn>mx[p])
		added=1,mx[p]=cn;
	}
	on|=(!added);
    }
    for(int i=0;i<MAX;i++)
	if(cnt[i]==1)
	    mx[i]=1;
    for(int i=0;i<MAX;i++)
	for(int j=0;j<mx[i];j++)
	    ans=1ll*ans*i %mod;
    printf("%d\n",on+ans);
    return 0;
}