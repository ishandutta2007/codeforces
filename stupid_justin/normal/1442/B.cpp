#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int M=5005;
struct TwoList
{
    int pre,nxt;
}L[N];
void Delete(int x)
{
    if (L[x].pre) L[L[x].pre].nxt=L[x].nxt;
    if (L[x].nxt) L[L[x].nxt].pre=L[x].pre;
}
 
int a[N],b[N],tag[N],pos[N];
int n,m;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int ans=1;
		cin>>n>>m;
		for (int i;i<=n;i++) tag[i]=0;
		for (int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
		for (int i=1;i<=m;i++) cin>>b[i],b[i]=pos[b[i]],tag[b[i]]=1;
		for (int i=1;i<=n;i++)
    	{
    	    L[i].pre=i-1;
    	    L[i].nxt=i+1;
    	}
        L[n].nxt=0;
    	tag[0]=1;
		for (int i=1;i<=m;i++)
		{
			if (tag[L[b[i]].pre])
			{
				if (tag[L[b[i]].nxt]) {ans=0;}
				else Delete(L[b[i]].nxt);
			}
			else
			{
				if (tag[L[b[i]].nxt]) Delete(L[b[i]].pre);
				else 
				{
					ans=ans*2%998244353;
					Delete(L[b[i]].nxt);
				}
			}
			tag[b[i]]=0;
		}
		cout<<ans<<endl;
	}
	
}