#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int lane=1;
    while(k>2*m)
        k-=2*m,lane++;
    int desk=1;
    while(k>2)
        k-=2,desk++;
    if (k==1)
        cout<<lane<<' '<<desk<<' '<<'L'<<endl;
    else
        cout<<lane<<' '<<desk<<' '<<'R'<<endl;
}