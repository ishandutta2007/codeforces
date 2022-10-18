#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;



int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n,h,a,b,k;
   cin>>n>>h>>a>>b>>k;
   for (int i=1; i<=k; i++)
   {
       int f1,t1,f2,t2;
       cin>>f1>>t1>>f2>>t2;
       if (f1==f2) cout<<abs(t1-t2)<<"\n"; else
       if (t1>=a&&t1<=b) cout<<abs(f1-f2)+abs(t1-t2)<<"\n"; else
       if (t1>b) cout<<t1-b+abs(f1-f2)+abs(b-t2)<<"\n"; else
       cout<<a-t1+abs(f1-f2)+abs(a-t2)<<"\n";
   }
}