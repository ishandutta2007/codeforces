#include<bits/stdc++.h>
using namespace std;
long long a[100009];
string se ="cslnb", fi = "sjfnb";
main(){
   long long n,S=0;
   cin >> n;
   for(long long i = 1; i <= n; i++)
    cin >> a[i],S+=a[i];
   sort(a + 1, a+n+1);
   long long k =0;
   for(long long i = 3; i <= n; i++){
        if(a[i] == a[i- 1] && a[i-1] - a[i-2] <= 1) {cout << se<<endl; return 0;}
   }
   for(int i = 2; i <= n; i++)
    if(a[i] == a[i-1]) k++;
   if(k > 1 || (n > 1&& a[2] == 0) ) cout<<se<<endl;
   else if((S -n*(n-1)/2)%2==0) cout<<se<<endl; else cout<<fi<<endl;


}
//0