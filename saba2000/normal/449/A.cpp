#include <iostream>
#include <algorithm>
using namespace std;
long long int f(long long int n,long long int m,long long int k)
{long long int a,b=m; 
if (n+m-2<k) return -1;
else  
{if (k>=n-1) {a=1; k-=n-1;} else
if (n%(k+1)==0) {a=n/(k+1); k=0;} else
{a=(n-(n%(k+1)))/(k+1); k=0;}
if (k!=0) if (m%(k+1)==0) b=m/(k+1);  else
b=(m-(m%(k+1)))/(k+1); 
return a*b; }
}
int main ()
{long long int n,m,k,a,b=1;
cin>>n>>m>>k; b=m;

if (n+m-2<k) cout<<-1<<endl;
else  
cout<<max(f(n,m,k),f(m,n,k))<<endl;
return 0;
}