#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ile=1;
    // a to sciana
    // b to sufit
    int iloscB=0;
    int iloscA=0;
    int tmp=n;

    if(b>a)
    while (iloscA<4 or iloscB<2)
    {
        if(n-b>=0 and iloscB<2)
        {
           // cout<<1<<endl;
            n-=b;
            iloscB++;
        }
        if(n-a>=0 and iloscA<4)
        {
        //    cout<<2<<endl;
            n-=a;
            iloscA++;
        }
        
        if( (n<a and n<b) or (n<a and iloscB==2)  or (n<b and iloscA==4))
        {
           // cout<<"zmniejszam : "<<n<<endl;
            if(iloscA<4 or iloscB<2)ile++;
            n=tmp;
        }
        //cout<<"n: "<<n<<"  ilosc: "<<ile<<endl;
      // cout<<"B: "<<iloscB<<" "<<"A: "<<iloscA<<endl<<endl;
    }
    else
    {
        while (iloscA<4 or iloscB<2)
        {
            if(n-a>=0 and iloscA<4)
            {
                //    cout<<2<<endl;
                n-=a;
                iloscA++;
            }
            if(n-b>=0 and iloscB<2)
            {
                // cout<<1<<endl;
                n-=b;
                iloscB++;
            }
          
            
            if( (n<a and n<b) or (n<a and iloscB==2)  or (n<b and iloscA==4))
            {
                if(iloscA<4 or iloscB<2)ile++;
                n=tmp;
            }
        }
    }
    if(ile==0)ile++;
    cout<<ile<<endl;
    return 0;
}