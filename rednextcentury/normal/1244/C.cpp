#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n,p,w,d;
    cin>>n>>p>>w>>d;
    for (long long i=0;i<w;i++) {
        if (i*d > p)break;
        if ((p-i*d)%w==0) {
            long long x = i;
            long long y = (p-i*d)/w;
            long long z = n-x-y;
            if (z>=0 && y>=0 && z>=0){
                cout<<y<<' '<<x<<' '<<z<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}