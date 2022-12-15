#include<iostream>
#include<vector>

using namespace std;

int a[2000001];
long long st[8000001];
long long d[8000001];
long long c[8000001];
long long all[8000001];

long long k;

vector<int> init(int ind,int l,int r)
{
    if(l==r)
    {
        st[ind]=0;
        vector<int> v3;
        v3.push_back(a[l]);
        return v3;
    }

    int mid=(l+r)/2;

    vector<int> v1,v2,v3;

    v1=init(2*ind,l,mid);
    v2=init(2*ind+1,mid+1,r);

    //cout<<v1.size()<<" "<<v2.size()<<endl;

    int i=0,j=0;
    long long res=0;

    while(i<v1.size() && j<v2.size())
    {
        //cout<<v1[i]<<" --- "<<v2[j]<<endl;
        if(v1[i]<=v2[j])
        {
            v3.push_back(v1[i]);
            i++;
            continue;
        }

        res+=v2.size()-i;
        v3.push_back(v2[j]);
        j++;
    }

    for(i;i<v1.size();i++)
        v3.push_back(v1[i]);
    for(j;j<v2.size();j++)
        v3.push_back(v2[j]);

    st[ind]=res+st[2*ind]+st[2*ind+1];

    d[r-l+1]+=st[ind];

    long long curr=1;

    for(i=1;i<v3.size();i++)
    {
        if(v3[i]==v3[i-1])
            curr++;
        else
        {
            all[r-l+1]+=curr*(v3.size()-i);
            curr=1;
        }
    }

    //cout<<st[ind]<<" = "<<l<<" "<<r<<endl;

    return v3;
}
long long update(long long x)
{
    long long diff=-d[x],x2=x;

    //cout<<d[x]<<" -- "<<all[x]<<endl;

    d[x]=all[x]-d[x];

    //cout<<diff<<endl;

    diff+=d[x];

    //cout<<diff<<endl;

    //cout<<d[k]<<endl;

    for(x=x*2;x<=k;x*=2)
        d[x]+=diff;

   // cout<<d[k]<<endl;

    for(x2=x2/2;x2>=1;x2/=2)
    {
        //cout<<x<<endl;
        d[x2]=all[x2]-d[x2];
    }

    //cout<<d[k]<<endl;

    return d[k];
}
int main ()
{
    int n,i,m,q;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    k=1<<n;

    for(i=1;i<=k;i++)
        cin>>a[i];

    cin>>m;

    init(1,1,k);

    for(i=0;i<m;i++)
    {
        cin>>q;
        q=1<<q;
        cout<<update(q)<<"\n";
    }

    return 0;
}
/*
3
1007662 530428 760991 855837 741915 758644 162260 200908
1
1
*/