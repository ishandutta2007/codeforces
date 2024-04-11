# include <algorithm>
# include <iostream>
using namespace std;
int main ()
{
    int k,w,n;
    cin>>k>>n>>w;
    cout<<max(0,(w*(w+1)*k)/2-n)<<endl;
}