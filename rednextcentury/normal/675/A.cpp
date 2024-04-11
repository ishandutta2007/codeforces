
#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long a,b,c;
    cin>>a>>b>>c;
    if (((c==0 && a==b ) || (c!=0 && (b-a)%c==0) ) && (b-a)*c>=0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}