#include<bits/stdc++.h>
using namespace std;
int a[100009];
main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
   int x=1;
   a[n]=-1;
   vector<int> v;
   for (int i =1; i<=n; i++)
   {
       if(a[i]==a[i-1]) x++;
       else
       {
           v.push_back(x);
           x=1;
       }
   }
   int M=0,W=1;
   for(int i=0; i<v.size(); i++)
   {
       if(v[i]%2==0)
       {
           if(M) M=1,W=1;
           else M=0,W=1;
       }
       else
       {
           if(W) W=1,M=1;
           else W=0,M=1;
       }
   }
   if(M) cout<<"Conan"<<endl;
   else cout<<"Agasa"<<endl;


}