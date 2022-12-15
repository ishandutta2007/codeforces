#include<iostream>

using namespace std;

long long cnt_dig(long long x)
{
    long long res=0;

    while(x>=10)
    {
        res++;
        x/=10;
    }

    return res+1;
}

long long arr[10];

long long solve(long long b, long long dig,bool e)
{
    long long pb=b,i,j,res=0,st=1;

    if(!dig)return 0;

    if(!e)
    {
        for(i=9;i>=0;i--)
        {
            for(j=0;j<arr[i];j++)
            {
                res*=10;
                res+=i;
            }
        }

        return res;
    }

    for(i=1;i<dig;i++)
    {
        pb/=10;
        st*=10;
    }

    if(arr[pb])
    {
        arr[pb]--;
        res=solve(b-pb*st,dig-1,1);
        if(res!=-1)
        {
            return pb*st+res;
        }
        arr[pb]++;
    }

    for(i=pb-1;i>=0;i--)
    {
        if(arr[i])
        {
            arr[i]--;
            return i*st+solve(b-pb*st,dig-1,0);
        }
    }

    return -1;
}

int main ()
{
    long long a,b,i;

    cin>>a>>b;

    if(cnt_dig(a)<cnt_dig(b))
    {
        while(a>=10)
        {
            arr[a%10]++;
            a/=10;
        }
        arr[a]++;

        for(i=9;i>=0;i--)
        {
            while(arr[i])
            {
                cout<<i;
                arr[i]--;
            }
        }

        cout<<endl;

        return 0;
    }

    long long pa=a;

    while(pa>=10)
    {
        arr[pa%10]++;
        pa/=10;
    }
    arr[pa]++;

    cout<<solve(b,cnt_dig(b),1)<<endl;

    return 0;
}