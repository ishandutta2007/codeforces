#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int now1=0,now2=0;
    for (int i=0;;i++)
    {

        if (i>=t && i%t==0)
            now1+=k,now2+=k;
        if (i>=d+t && (i-d)%t==0)
            now2+=k;
        if (now1>=n || now2>=n)
            break;
    }
    if (now1<n)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}