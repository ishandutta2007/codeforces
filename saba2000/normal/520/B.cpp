#include <iostream>
using namespace std;
int j(int n, int m)
{int k=0,l=0,l1;
cin>>n>>m; l1=n;
while (n<m) {n*=2; k++;}
k+=n-m; n=l1;
if (n>m ) l=k+1;
else {if (n!=(m+1)/2) l+=j(n,(m+1)/2); n=(m+1)/2; {while (n>(m+1)/2) {n--; l++;}
l+=1+m%2;} 
}
return min(l,k);
}
int main ()
{int n,m;
cout<<j(n,m);

return 0;
}