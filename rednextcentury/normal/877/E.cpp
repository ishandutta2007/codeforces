#include <bits/stdc++.h>
#define int long long

using namespace std;
bool Vis[200005];
vector < int > G[200005];
int tree[2000005],t=0,in[200005],out[200005],mx=-1,lazy[2000005],Arr[2000005];
void Build(int node=1,int Start=1,int End=400005){
    if(Start==End){
        tree[node]=Arr[Start];
        return;
    }
    int mid=(Start+End)/2;
    Build(2*node,Start,mid);
    Build(2*node+1,mid+1,End);

    tree[node] = tree[node*2] + tree[node*2+1];

}
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si] != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        lazy[si]%=2;
        if(lazy[si])
        tree[si] = (se-ss+1)-tree[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 ]   +=lazy[si];
            lazy[si*2 + 1]   +=lazy[si] ;
        }

        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] =(se-ss+1)-tree[si];

        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 ]   ++;
            lazy[si*2 + 1]   ++;
        }
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (ss+se)/2;
    updateRangeUtil(si*2, ss, mid, us, ue);
    updateRangeUtil(si*2+1, mid+1, se, us, ue);

    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2] + tree[si*2+1];
}
int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        lazy[si]%=2;
        if(lazy[si])
        tree[si] = (se-ss+1)-tree[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2] +=lazy[si];
            lazy[si*2+1] +=lazy[si];
        }

        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si) +
           getSumUtil(mid+1, se, qs, qe, 2*si+1);
}
void DFS(int v){

    if(Vis[v])  return;
    Vis[v]=1;
    in[v]=++t;
    for(auto j:G[v]){
        DFS(j);
    }
    out[v]=t;
    mx=max(mx,out[v]);
}

 main()
{
   int n;
   cin>>n;
   for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        G[i].push_back(x);
        G[x].push_back(i);
   }

   DFS(1);
   for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x)
        Arr[in[i]]=1;
   }
   Build();

   int q;
   cin>>q;
   while(q--){

    string s;
    int x;
    cin>>s>>x;
    if(s=="get"){
        cout<<getSumUtil(1,400005,in[x],out[x],1)<<endl;
    }else{
    updateRangeUtil(1,1,400005,in[x],out[x]);
    }

   }


    return 0;
}