#include<iostream>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;

int main ()
{
    long long n,q,i,x,y,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    for(i=0;i<q;i++)
    {
        cin>>x>>y;

        res=0;

        if((x+y)%2==0)
        {
            if(x%2==1)
            {
                res+=(x/2)*(n);
                res+=(y+1)/2;
            }
            else
            {
                res+=(x/2-1)*(n)+n/2+n%2;
                res+=y/2;
            }
        }
        else
        {
            res+=n*n/2+n%2;
            if(x%2==1)
            {
                res+=(x/2)*(n);
                res+=y/2;
            }
            else
            {
                res+=(x/2-1)*(n)+n/2;
                res+=(y+1)/2;
            }
        }

        cout<<res<<"\n";
    }

    return 0;
}