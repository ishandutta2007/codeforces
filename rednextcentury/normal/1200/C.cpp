#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
    if (y==0)return x;
    if (x==0)return y;
    return gcd(y%x,x);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        long long n,m,q;
        cin>>n>>m>>q;
        long long GCD = gcd(n,m);
        long long l1 = n/GCD;
        long long l2 = m/GCD;
        while(q--)
        {
            long long sx,sy,ex,ey;
            cin>>sx>>sy>>ex>>ey;
            if (sx==1 && ex==1)
            {
                if ((sy-1)/l1 == (ey-1)/l1)
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if (sx==2 && ex==2)
            {
                if ((sy-1)/l2 == (ey-1)/l2)
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else
            {
                if (sx==2)swap(sy,ey);
                // sx = 1, ex = 2
                long long L = (sy-1)/l1;
                long long R = L*l2 + l2;
                L = L*l2+1;
                if (ey>=L && ey<=R)
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

}