#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<int> 
#define vv vector<v>
#define p pair<int,int>

int LIM=4e6+10000;

v tree(4*LIM);
v lazy(4*LIM);
int MAX;
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        tree[node] += lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        tree[node] += val;
        if(start != end)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = max(tree[node*2],tree[node*2+1]);        // Updating root with max value 
}

void update(int l,int r,int value)
{
	updateRange(1,1,MAX,l,r,value);
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        tree[node] += lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return max(p1,p2);
}

int query(int l,int r)
{
	return queryRange(1,1,MAX,l,r);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin>>n>>r;
    vector<p> arr(n+1);
    vv points(8e6+100);
    int diff=2e6+10;
    int mini=1e9;
    int maxi=-1e9;
    for (int i=1; i<=n; i++)
    {
    	int a,b;
    	cin>>a>>b;
    	arr[i]=p(a+b,b-a+diff);
    	int x=a+b;
    	int y=b-a+diff;
    	mini=min(mini,x);
    	maxi=max(maxi,x);
    	if (x>=0)
    		points[x].push_back(i);
    	else
    		points[4e6+50-x].push_back(i);
    }
    MAX=4e6+1000;
    int d=2*r;
    int left=mini-2*r-10;
    int right=left+2*r;
    int ans=0;
 	while (left<=maxi)
 	{
 		left++;
 		right++;
 		int ri;
 		if (right>=0)
 			ri=right;
 		else
 			ri=4e6+50-right;
 		int li;
 		if (left-1>=0)
 			li=left-1;
 		else
 			li=4e6+50-(left-1);
 		for (int j=0; j<points[ri].size(); j++)
 		{
 			p temp=arr[points[ri][j]];
 			int y=temp.second;	
 			update(max(1,y-r),min(y+r,MAX),1);
 		}
 		for (int j=0; j<points[li].size(); j++)
 		{
 			p temp=arr[points[li][j]];
 			int y=temp.second;
 			update(max(1,y-r),min(y+r,MAX),-1);
 		}
  		//cout<<left<<endl;
 		int temp=query(1,MAX);
 		ans=max(ans,temp);
 	}
 	cout<<ans<<endl;
    return 0;
}