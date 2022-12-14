# include <iostream>
int GCD(int a,int b)
{
    if (a%b==0)
        return b;
    if (b%a==0)
        return a;
    return GCD(b%a,a);
}
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int h=GCD(c,d);
    c/=h,d/=h;
    cout<<min(a/c,b/d)*c<<" "<<min(a/c,b/d)*d<<endl;
}