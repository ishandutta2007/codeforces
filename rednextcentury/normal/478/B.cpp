# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long kmin;
    long long kmax;
    long long now1=n/m;
    kmin=((now1*(now1-1)/2)*(m-n%m)+now1*(now1+1)/2*(n%m));
    kmax=(n-m+1)*(n-m)/2;
    cout<<kmin<<" "<<kmax<<endl;
}