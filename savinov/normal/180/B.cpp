#include <iostream>

using namespace std;

int ost[202];
int b,d;
bool t[102];
bool tst=true;

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

bool check2()
{
    int i=2*d;
    if (ost[i]!=0) return false;
    while (ost[i]==0) i--;
    if (!tst) cout << "2-type\n" << i+1;
    return true;
}
bool check3()
{
    bool ok=true;
    for (int i=0;i<=2*d;i++) if (ost[i]!=1) ok=false;
    if (!tst) if (ok) cout << "3-type\n";
    return ok;
}
bool check11()
{
    bool ok=true;
    for (int i=0;i<=2*d;i++) if (ost[i]!=(2*d+2*((i+1)%2)-1)%d) ok=false;
    if (!tst) if (ok) cout << "11-type\n";
    return ok;
}

bool check6()
{
    bool ok=false;
    for (int i=2;i*i<=d;i++)
    {
        if (d%i==0)
        {
            if (gcd(i,d/i)==1) ok=ok||(t[i]&&t[d/i]);
        }
    }

    if (!tst) if (!ok) cout << "7-type\n"; else cout << "6-type\n";
    return ok;
}


int main()
{


    ost[0]=1;
    cin >> b >> d;
    int d1=d;
    t[1]=false;

    for (d=2;d<=d1;d++)
    {
        for (int i=1;i<=2*d;i++)
    {
        ost[i]=(b*ost[i-1])%d;
        //cout << ost[i] << " ";
    }
    t[d]=check2()||check3()||check11()||check6();
    //cout << d << " " << t[d] << "\n";
    }
    d=d1;
    tst=false;
    if (check2()) return 0;
    if (check3()) return 0;
    if (check11()) return 0;
    if (check6()) return 0;

}