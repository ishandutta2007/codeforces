# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=1;
    while((x+1)*(x+1)<=n)
        x++;
    cout<<x*4+((n-x*x)/x)*2+((n-x*x)%x>0)*2<<endl;
}