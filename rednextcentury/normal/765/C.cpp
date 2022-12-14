#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,a,b;
    cin>>k>>a>>b;
    if (k==1)
    {
        cout<<a+b<<endl;
        return 0;
    }
    long long ret=(a/k)+(b/k);
    long long la=a%k,lb=b%k;
    if ((la/(k-1)+(la%(k-1)>0))<=b/k && (lb/(k-1)+(lb%(k-1)>0))<=a/k)
        cout<<ret<<endl;
    else cout<<-1<<endl;
}