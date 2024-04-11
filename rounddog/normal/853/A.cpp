#include<cmath>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define maxn 300050

using namespace std;
typedef long long int ll;

struct Node{  
    ll x, y;  
    Node( ll a= 0, ll b= 0 ):  
        x(a), y(b) {}  
};  

struct cmp{  
    bool operator() ( Node a, Node b ){   
        return a.x<b.x; 
    }  
}; 

priority_queue<Node, vector<Node>, cmp> q;

ll c[maxn],ans,a[maxn],d[maxn],n,k,j;

int main()
{
	scanf("%d%d",&n,&k);
	ans=0;j=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans-=a[i]*i;
	}
	for (int i=1;i<=k;i++)
	{
		j++;
		q.push(Node(a[j],j));
	}
	for (int i=1;i<=n;i++)
	{
		if (j<n){
		    j++;
			q.push(Node(a[j],j));
		}
		d[q.top().y]=i+k;
		ans+=q.top().x*(k+i); 
		q.pop();
	}
	printf("%I64d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",d[i]); printf("\n");
	return 0;
}