#include<iostream>
#include<set>

using namespace std;

const int maxi=100007;

int a[maxi];
int nextN[maxi];
multiset<int> Set;
int st[4*maxi];

void init(int ind,int l,int r)
{
    if(l==r)
    {
        st[ind]=maxi;
        return;
    }

    int mid=(l+r)/2;

    init(2*ind,l,mid);
    init(2*ind+1,mid+1,r);

    st[ind]=maxi;

    return;
}

void update(int ind,int l,int r,int s,int val)
{
    if(s<l || s>r)
        return;
    if(l==r)
    {
        st[ind]=val;
        return;
    }

    int mid=(l+r)/2;

    update(2*ind,l,mid,s,val);
    update(2*ind+1,mid+1,r,s,val);

    st[ind]=min(st[2*ind],st[2*ind+1]);
}

int query(int ind,int l,int r,int sl,int sr)
{
    if(sl>r || sr<l)
        return maxi;
    if(sl<=l && r<=sr)
        return st[ind];

    int mid=(l+r)/2;

    return min(query(2*ind,l,mid,sl,sr),query(2*ind+1,mid+1,r,sl,sr));
}

int main ()
{
    int n,s,l,i,j=0;
    auto it=Set.begin();

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s>>l;

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(j=1;j<=n;j++)
    {
        Set.insert(a[j]);
        if(*Set.rbegin()-*Set.begin()>s)
            break;
    }
    if(j!=n+1)
    {
        it=Set.find(a[j]);
        Set.erase(a[j]);
    }
    j--;

    nextN[1]=j;

    for(i=2;i<=n;i++)
    {
        it=Set.find(a[i-1]);
        Set.erase(it);
        for(j=j+1;j<=n;j++)
        {
            Set.insert(a[j]);
            if(*Set.rbegin()-*Set.begin()>s)
                break;
        }
        if(j!=n+1)
        {
            it=Set.find(a[j]);
            Set.erase(a[j]);
        }
        j--;
        nextN[i]=j;
    }

    init(1,1,n+1);

    update(1,1,n+1,n+1,0);

    for(i=n;i>=1;i--)
        if(nextN[i]-i+1>=l)
        {
            //cout<<i<<" - "<<nextN[i]+1<<" ";
            //cout<<query(1,1,n+1,i+l,nextN[i]+1)<<endl;
            update(1,1,n+1,i,query(1,1,n+1,i+l,nextN[i]+1)+1);
        }

    int res=query(1,1,n+1,1,1);

    if(res>=maxi)
        cout<<"-1\n";
    else
        cout<<res<<"\n";

    return 0;
}