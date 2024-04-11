#include<iostream>
#include<cmath>
using namespace std;
bool check(int p)
{for (int i=2; i<=(int)sqrt(p);i++)
if (p%i==0) return 0; 
return 1;}
main()
{int n; cin>>n;
if (check(n)) {cout<<1<<endl;return 0;}
if (n%2==1) {if (check(n-2)) cout<<2<<endl; else cout<<3<<endl;}
if (n%2==0) cout<<2<<endl;

}