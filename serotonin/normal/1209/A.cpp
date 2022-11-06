#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz];

int main()
{
   int n;
   cin >> n;
   for(int i=0; i<n; i++) cin >> a[i];
   sort(a,a+n);

   int ans=0;
   for(int i=0; i<n; i++) {
      if(!a[i]) continue;
      ans++;
      for(int j=i+1; j<n; j++) {
         if(a[j] && a[j]%a[i]==0) a[j]=0;
      }
   }

   cout << ans << endl;
}