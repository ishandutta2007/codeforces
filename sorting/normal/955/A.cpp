#include<iostream>

using namespace std;

int main ()
{
    int hh,mm;
    int h,d,c,n;
    int p;
    double res,res2;

    cin>>hh>>mm>>h>>d>>c>>n;

    mm=hh*60+mm;
    p=20*60;

    if(mm>=p)
    {
        res=(int)c*(h/n);
        if(h%n>0)res+=c;
        res*=(double)8/10;

        cout<<res<<endl;

        return 0;
    }

    res=(int)c*(h/n);
    if(h%n>0)res+=c;

    res2=(int)c*((h+(p-mm)*d)/n);
    if((h+(p-mm)*d)%n>0)res2+=c;
    res2*=(double)8/10;

    cout<<min(res,res2)<<endl;

    return 0;
}