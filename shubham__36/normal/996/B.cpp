#include <iostream>

using namespace std;

long long int f (long long int a,long long int n)
{
   if(a<0) return 0;
   if(a % n == 0)  return (a/n);
   else return (a/n + 1);
}

int main()
{
    long long int n,ans=1000000000,ans1;
    cin >> n;
    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin >>a[i];
    }
    for(long long int i=0;i<n;i++){
        if(f(a[i]-i,n) < ans) {ans1 = i+1; ans = f(a[i]-i,n);}
    }
    cout << ans1 << endl;
    return 0;
}