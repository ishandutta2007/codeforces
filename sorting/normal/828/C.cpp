#include<iostream>

using namespace std;

string a;
char res[2000001];
bool b[5000001];
long long maxi=1;

void update_range_sum(int ind,int l,int r,int sl,int sr,int x)
{
    int qr=sr+x,ql=sl+x;

    if(b[ind]==1)return;
    if(qr<l || ql>r)return;
    if(l==r)
    {
        res[l]=a[l-x];
        if(l>maxi)maxi=l;
        b[ind]=1;
    }
    else
    {
        int mid=(l+r)/2;
        update_range_sum(2*ind,l,mid,sl,sr,x);
        update_range_sum(2*ind+1,mid+1,r,sl,sr,x);

        if(b[2*ind]==1 && b[2*ind+1]==1)
        {
            b[ind]=1;
        }
    }
}

int main ()
{
    long long n,br=0,i,k,j,p,l;

    ios::sync_with_stdio(false);

    for(i=0;i<=2000001;i++)res[i]='a';

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a>>k;

        l=a.size()-1;

        for(j=0;j<k;j++)
        {
            cin>>p;
            update_range_sum(1,1,2000001,0,l,p);
        }
    }

    for(i=1;i<=maxi;i++)cout<<res[i];

    cout<<"\n";

    return 0;
}