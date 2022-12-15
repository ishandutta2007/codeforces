#include<bits/stdc++.h>
using namespace std;
bool prime(long long n)
{
    long long i=2;
    while(i*i<=n)
    {
        if (n%i==0 && i!=n)return 0;
        i++;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    
        if (prime(n))
            cout<<1<<endl;
        else if (prime(n-2))
            cout<<2<<endl;
        else if (n%2==0) cout<<2<<endl;
        else cout<<3<<endl;

}