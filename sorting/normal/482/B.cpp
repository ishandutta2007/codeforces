#include<iostream>

using namespace std;

long long st[400007];
long long queries[100007][3];
long long arr[100007][30];

void init(long long ind,long long l,long long r)
{
    if(l==r)
    {
        st[ind]=arr[l][0];
        //cout<<st[ind][w]<<endl;
        return;
    }

    long long mid=(l+r)/2;

    init(2*ind,l,mid);
    init(2*ind+1,mid+1,r);

    st[ind]=st[2*ind]&st[2*ind+1];

    return;
}

long long query(long long ind,long long l,long long r,long long sl,long long sr)
{
    if(l>sr || r<sl)
        return -1;
    if(sl<=l && r<=sr)
        return st[ind];

    long long mid=(l+r)/2;

    long long p1=query(2*ind,l,mid,sl,sr);
    long long p2=query(2*ind+1,mid+1,r,sl,sr);

    if(p1==-1)
        return p2;
    if(p2==-1)
        return p1;

    return p1&p2;
}

int main ()
{
    long long n,m,i,j,p;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;



    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
            cin>>queries[i][j];

        for(j=0;j<30;j++)
        {
            p=1<<j;
            if(queries[i][2]&p)
            {
                //update(1,1,n,queries[i][0],queries[i][1],j);
                arr[queries[i][0]][j]+=1;
                arr[queries[i][1]+1][j]+=-1;
                //cout<<j<<" j"<<endl;
            }
        }
    }

    //cout<<arr[1][0]<<" "<<arr[2][0]<<" "<<arr[3][0]<<endl;

    for(i=0;i<30;i++)
        for(j=2;j<=n;j++)
            arr[j][i]+=arr[j-1][i];

    for(i=0;i<30;i++)
    {
        p=1<<i;
        for(j=1;j<=n;j++)
            if(arr[j][i]>0)
                arr[j][i]=p;
    }

    for(i=1;i<30;i++)
        for(j=1;j<=n;j++)
            arr[j][0]+=arr[j][i];


    //cout<<arr[1][0]<<" "<<arr[2][0]<<" "<<arr[3][0]<<endl;


    init(1,1,n);

    //cout<<st[1][0]<<" "<<st[2][0]<<" "<<st[3][0]<<endl;

    long long t;

    for(i=0;i<m;i++)
    {
        t=query(1,1,n,queries[i][0],queries[i][1]);
        for(j=0;j<30;j++)
        {
            p=1<<j;
            if(!(queries[i][2]&p))
            {
                //cout<<query(1,1,n,queries[i][0],queries[i][1],j)<<" "<<j<<endl;
                if(t&p)
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }

    cout<<"YES\n";

    for(i=1;i<=n;i++)
    {
        cout<<arr[i][0]<<" ";
    }
    cout<<"\n";

    return 0;
}
/*
5 3
1 3 1
2 4 1
3 4 1
*/