#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int> a[100001];
int n,cnt=1;

int maxi=-1,res=0;
int amount[100001];
int lst[400001],rst[400001];
bool t[400001];
//int lp[400001];

#define endl "\n"

void init(int ind,int l,int r)
{
    if(l==r)
    {
        lst[ind]=1;
        rst[ind]=n;
        return;
    }

    int mid=(l+r)/2;

    init(2*ind,l,mid);
    init(2*ind+1,mid+1,r);

    lst[ind]=1;
    rst[ind]=n;
}

void update(int ind,int l,int r,int sl,int sr,int q)
{
    if(t[ind] && l!=r)
    {
        t[2*ind]=1;
        t[2*ind+1]=1;
        lst[2*ind]=lst[ind];
        lst[2*ind+1]=lst[ind];
        rst[2*ind]=rst[ind];
        rst[2*ind+1]=rst[ind];
        t[ind]=0;
    }
    if(sl>r || sr<l)
        return;
    if(l==r)
    {
        if(l<q)
        {
            lst[ind]=sl;
            rst[ind]=q-1;
        }
        else
        {
            if(l==q)
            {
                lst[ind]=l;
                rst[ind]=l;
            }
            else
            {
                lst[ind]=q+1;
                rst[ind]=sr;
            }
        }
        return;
    }
    if(sl<=l && r<=q-1)
    {
        lst[ind]=sl;
        rst[ind]=q-1;
        t[ind]=1;
        return;
    }
    if(q+1<=l && r<=sr)
    {
        lst[ind]=q+1;
        rst[ind]=sr;
        t[ind]=1;
        return;
    }

    int mid=(l+r)/2;

    update(2*ind,l,mid,sl,sr,q);
    update(2*ind+1,mid+1,r,sl,sr,q);
}

pair<int,int> query(int ind,int l,int r,int q)
{
    if(q<l || q>r)
        return make_pair(-1,-1);
    if(l==r)
    {
        return make_pair(lst[ind],rst[ind]);
    }
    if(t[ind])
    {
        t[2*ind]=1;
        t[2*ind+1]=1;
        lst[2*ind]=lst[ind];
        lst[2*ind+1]=lst[ind];
        rst[2*ind]=rst[ind];
        rst[2*ind+1]=rst[ind];
        t[ind]=0;
    }

    int mid=(l+r)/2;
    pair<int,int> p1,p2;

    p1=query(2*ind,l,mid,q);
    p2=query(2*ind+1,mid+1,r,q);

    if(p1.first==-1)
        return p2;

    return p1;
}

int main ()
{
    int i;
    pair<int,int> p;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i].first;
        //x[i]=a[i].first;
        a[i].second=i;
    }

    sort(a+1,a+1+n);

    init(1,1,n);
    amount[n]=1;

    for(i=n;i>=2;i--)
    {
        //cout<<i<<endl;
        ///split array here
        p=query(1,1,n,a[i].second);

        //cout<<p.first<<" "<<p.second<<endl;

        update(1,1,n,p.first,p.second,a[i].second);

        amount[p.second-p.first+1]--;
        cnt--;
        if(p.second-a[i].second>0)
        {
            amount[p.second-a[i].second]++;
            cnt++;
        }
        if(a[i].second-p.first>0)
        {
            amount[a[i].second-p.first]++;
            cnt++;
        }

        //cout<<cnt<<endl;

        if(cnt==0)
        {
            if(cnt>=maxi)
            {
                maxi=cnt;
                res=a[i-1].first+1;
            }
            continue;
        }

        if(i==1)
        {
            if(cnt>=maxi)
            {
                maxi=cnt;
                res=a[i-1].first+1;
            }
            continue;
        }
        if((i-1)%cnt==0 && amount[(i-1)/cnt]==cnt)
        {
            if(cnt>=maxi)
            {
                maxi=cnt;
                res=a[i-1].first+1;
            }
        }
    }

    if(maxi<=0)
    {
        res=a[n].first+1;
    }

    cout<<res<<endl;

    return 0;
}