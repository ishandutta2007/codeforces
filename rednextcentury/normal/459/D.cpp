

    #include <iostream>
    #include <algorithm>
    #include <map>
    #define mid (l+r)/2
    #define left x*2
    #define right x*2+1
    using namespace std;
    int tree[5000000];
    int a[2000000];
    int b[2000000];
    int c[2000000];
    int lastx[1000000];
    int lasty[1000000];
    map<int,int> compress;
    map<int,int> decompress;
    struct s
    {
        int val;
        int idx;
    };
    s f[1000000];
    bool comp(s a,s b)
    {
        return a.val<b.val;
    }
    void update(int x,int l,int r,int v)
    {
        if (v<l || v>r)
            return;
        if (l==r && l==v)
            tree[x]++;
        else
        {
            update(left,l,mid,v);
            update(right,mid+1,r,v);
            tree[x]=tree[left]+tree[right];
        }
    }
    int query(int x,int l,int r,int s,int e)
    {
        if (e<l || s>r)
            return 0;
        else if (l>=s && r<=e)
            return tree[x];
        return query(left,l,mid,s,e)+query(right,mid+1,r,s,e);
    }
    int main()
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>b[i];
            f[i].val=b[i];
            f[i].idx=i;
        }
        sort(f,f+n,comp);
        decompress[0]=f[0].val;
        compress[f[0].val]=0;
        int now=0;
        for (int i=1;i<n;i++)
        {
            if (f[i].val!=f[i-1].val)
                now++;
            decompress[now]=f[i].val;
            compress[f[i].val]=now;
        }
        for (int i=0;i<n;i++)
            b[i]=compress[b[i]];
        c[0]=1;
        lastx[b[0]]=1;
        for (int i=1;i<n;i++)
        {
            c[i]=lastx[b[i]]+1;
            lastx[b[i]]++;
        }
        a[1]=1;
        lasty[b[n-1]]=1;
        update(1,1,n,1);
        long long ans=0;
        for (int i=n-2;i>=0;i--)
        {
            ans+=query(1,1,n,0,c[i]-1);
            a[lasty[b[i]]+1]++;
            update(1,1,n,lasty[b[i]]+1);
            lasty[b[i]]++;
        }
        cout<<ans<<endl;
    }