#include<iostream>

using namespace std;

long long blc[50],blr[50],whc[50],whr[50];
long long st[52];

long long stf(int x)
{
    if(x==0)return 1;
    if(st[x]>0)return st[x];

    return st[x]=2*stf(x-1);
}

int main ()
{
    long long n,m,i,j,x,res=0;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>x;

            if(x==0)
            {
                whc[j]++;
                whr[i]++;
            }
            else
            {
                blc[j]++;
                blr[i]++;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        //cout<<whr[i]<<" "<<blr[i]<<endl;
        res+=stf(whr[i])-whr[i]-1;
        res+=stf(blr[i])-blr[i]-1;
    }

    for(i=0;i<m;i++)
    {
        //cout<<whr[i]<<" "<<blr[i]<<endl;
        res+=stf(whc[i])-whc[i]-1;
        res+=stf(blc[i])-blc[i]-1;
    }

    res+=n*m;

    cout<<res<<endl;

    return 0;
}