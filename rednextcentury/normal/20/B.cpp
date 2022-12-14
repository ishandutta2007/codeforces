#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long A,B,C;
    cin>>A>>B>>C;
    long long D = B*B-4*A*C;
    if (A==0 && B==0 && C==0)cout<<-1<<endl;
    else if (A==0)
    {
        if (B==0)cout<<0<<endl;
        else cout<<1<<endl<<setprecision(10)<<fixed<<((long double)-C)/B<<endl;
    }
    else if (D<0)cout<<0<<endl;
    else if (D==0)
    {
        long double a=A,b=B,c=C,d=D;
        long double x = -b/(2*a);

        cout<<1<<endl<<setprecision(10)<<fixed<<x<<endl;
    }
    else
    {
        long double a=A,b=B,c=C,d=D;
        long double x1 = (-b-sqrt(d))/(2*a);
        long double x2 = (-b+sqrt(d))/(2*a);
        if (x1>x2)swap(x1,x2);
        cout<<2<<endl<<setprecision(10)<<fixed<<x1<<endl<<x2<<endl;
    }

}