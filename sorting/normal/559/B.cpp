#include<iostream>
#include<cstdlib>

#define MAX 200002
#define MOD 100007
#define BASE 257

using namespace std;

long long pow[MAX];
long long hash1[MAX],hash2[MAX];

string a,b;

void init()
{
    hash1[0]=a[0];
    for(int i=1;i<a.size();i++)
        hash1[i]=(hash1[i-1]*BASE+a[i])%MOD;

    hash2[0]=b[0];
    for(int i=1;i<b.size();i++)
        hash2[i]=(hash2[i-1]*BASE+b[i])%MOD;

    pow[0]=1;
    for(int i=1;i<b.size();i++)
        pow[i]=(pow[i-1]*BASE)%MOD;
}

long long make_hash1(int l,int r)
{
    long long p1=hash1[r],p2,res;

    if(l==0)p2=0;
    else p2=hash1[l-1];

    res=(p1-(p2*pow[r-l+1])%MOD+MOD);

    while(res>=MOD)res-=MOD;

    return res;
}

long long make_hash2(int l,int r)
{
    long long p1=hash2[r],p2,res;

    if(l==0)p2=0;
    else p2=hash2[l-1];

    res=(p1-(p2*pow[r-l+1])%MOD+MOD);
    while(res>=MOD)res-=MOD;

    return res;
}

bool solve(int l1,int r1,int l2,int r2)
{
    bool x;

    if(make_hash1(l1,r1)==make_hash2(l2,r2))return 1;

    if((r1-l1+1)%2==0)
    {
        int mid1=l1+((r1-l1+1)/2)-1;
        int mid2=l2+((r2-l2+1)/2)-1;

        if(rand()%2==0)
        {
            if(solve(l1,mid1,l2,mid2))return solve(mid1+1,r1,mid2+1,r2);
            x=solve(l1,mid1,mid2+1,r2);
            if(!x)return 0;
            x=solve(mid1+1,r1,l2,mid2);
            if(!x)return 0;
            return 1;
        }
        else
        {
            if(solve(l1,mid1,mid2+1,r2))return solve(mid1+1,r1,l2,mid2);
            x=solve(l1,mid1,l2,mid2);
            if(!x)return 0;
            x=solve(mid1+1,r1,mid2+1,r2);
            if(!x)return 0;
            return 1;
        }
    }

    return 0;
}

int main ()
{
    ios::sync_with_stdio(false);

    cin>>a>>b;

    int l=a.size();

    init();

    if(solve(0,l-1,0,l-1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}