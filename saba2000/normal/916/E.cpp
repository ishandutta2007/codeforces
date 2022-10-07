#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
long long tree[MAX] = {0};  // To store segment tree
long long lazy[MAX] = {0};  // To store pending updates

/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(long long si, long long ss, long long se, long long us,
                     long long ue, long long diff)
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
        tree[si] += (se-ss+1)*lazy[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
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
        tree[si] += (se-ss+1)*diff;

        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    long long mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(long long n, long long us, long long ue, long long diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}


/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
long long getSumUtil(long long ss, long long se, long long qs, long long qe, long long si)
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
        tree[si] += (se-ss+1)*lazy[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }

        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // At this polong long we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    // If a part of this segment overlaps with the given
    // range
    long long mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
long long getSum(long long n, long long qs, long long qe)
{


    return getSumUtil(0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(long long arr[], long long ss, long long se, long long si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    long long mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(long long arr[], long long n)
{
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}
long long a[200009],n,c[200009],p[200009],T=0,l[200009],r[200009],q;
long long h[200009];
long long s[200009],e[200009];
vector<long long> v[200009],H[200009];
vector<long long> t;
long long pc[200009][25];
void dfs(long long x, long long d)
{
    l[x]=1000000000; r[x]=0;
    h[x]=d;
    H[h[x]].push_back(x);
    s[x]=t.size();
    t.push_back(x);
    for (long long i=0; i<v[x].size(); i++)
    {
        if(h[v[x][i]]) continue;

        dfs(v[x][i],d+1);
        l[x]=min(l[x],l[v[x][i]]);
        r[x]=max(r[x],r[v[x][i]]);
        t.push_back(x);
    }

//    cout << x << " "<< l[x] <<" "<<r[x]<<" "<<T<<endl;
    p[x]=T; l[x]=min(l[x],T);
    r[x]=max(r[x],T);
 //   cout << x << " "<< l[x] <<" "<<r[x]<<" "<<T<<endl;
    T++;
    e[x]=t.size()-1;
}
long long lca()
{
    for (long long i=0; i<=n; i++)
        h[i]=0;
     dfs(1,1);
    for (long long i=0; i<2*n-1; i++)
        {pc[i][0]=t[i];
        //cout << t[i] << " ";
        }
    for (long long i=1; (1<<i)<=2*n; i++)
    {
        for (long long j=0; j<2*n-(1<<i); j++)
    pc[j][i]=
    (h[pc[j][i-1]]>h[pc[j+(1<<(i-1))][i-1]] ?
      pc[j+(1<<(i-1))][i-1] : pc[j][i-1]);
    }
}
long long logg[200009];
long long LCA(long long a, long long b)
{
        long long u=s[a],v=e[a];
        long long LCA;
        long long l=s[b],r=e[b];
        if(u>l) {swap(u,l); swap(v,r); swap(a,b);}
        if(v>=r) LCA=a; else{
        long long L=r-u+1;
     //   cout << u << " "<< v <<" "<< l <<" " <<r <<endl;
        long long w=logg[L];
     //   cout << L <<" " << w << endl;
        long long x=pc[u][w],y=pc[r-(1<<w)+1][w];
        LCA=(h[x] > h[y] ? y : x);
        }
//cout << LCA << endl;
    return LCA;
}
bool  par(long long x, long long y)
{
    if (LCA(x,y)==x) return 1;
    else return 0;
}
long long findd(long long hh,  long long y)
{
    long long ll = 0, rr=H[hh].size()-1;
    while(ll<rr)
    {
        long long mid= (ll+rr+1)/2;
        if(l[H[hh][mid]]> p[y]) rr = mid-1;
        else ll=mid;
    }
    return H[hh][ll];
}
long long VV[200009];
main()
{

    cin >> n >> q;
     logg[1]=0;
    for (long long i = 2; i<=3*n; i++)
    {
        logg[i]=logg[i-1];
        if((1<<(logg[i]+1))<=i) logg[i]++;
    }
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
        for (long long i = 1; i < n; i++)
        {
            long long A,B;
            cin >> A >> B;
            v[A].push_back(B);
            v[B].push_back(A);
        }
   lca();
    for (long long i = 1; i <= n; i++)
        VV[p[i]] = a[i];
    constructST(VV, n);
    long long root = 1;
    while(q--)
    {
        long long t;
        cin >> t;
        if (t == 1)
        {
            cin >> root;
        }
        if (t == 2)
        {
            long long U,V,X;
            long long lc,ll;
            cin >> U >> V >> X;
            long long uv =LCA(U,V),ur=LCA(U,root),vr=LCA(V,root);
            if (!par(uv,root)) lc = uv;
            else if (h[ur]>h[vr]) lc=ur;
            else lc=vr;

          //  cout << uv<<" "<< ur <<" "<< vr<<" "<<lc<<endl;
            if (root == lc)
            {
                updateRange(n, 0, n-1, X);
            }
            else
            if (!par(lc,root))
            {
              //  cout << l[lc] <<" "<< r[lc] <<endl;
                updateRange(n, l[lc], r[lc], X);
            }
            else
            {
                updateRange(n, 0, n-1, X);
                long long LC=findd(h[lc]+1,root);
              //  cout << LC << endl;
                updateRange(n, l[LC], r[LC], -X);
            }
        }
        if (t == 3)
        {
            long long lc ;
            cin >> lc;
            long long ans=0;
            if (root == lc)
            {
                ans=getSum(n, 0, n-1);
            }
            else
            if (!par(lc,root))
            {
                ans=getSum(n, l[lc], r[lc]);
            }
            else
            {
                 ans+=getSum(n, 0, n-1);
                long long LC=findd(h[lc]+1,root);
                 ans-=getSum(n, l[LC], r[LC]);
            }
            cout << ans << endl;
        }
        //long long A,B;
        //cin >> A  >> B;
        //cout << LCA(A,B) << endl;
    }
}