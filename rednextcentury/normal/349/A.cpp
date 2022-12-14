#include <bits/stdc++.h>

using namespace std;

int main() {


  int n,sum=0,s25=0,s50=0;
  cin>>n;
   int x[n],counter=0;
  for(int i=0;i<n;i++)
     {
         cin>>x[i];
         if(x[i]-25<=sum)
          {++counter;
          if(x[i]==25)
          {sum+=x[i];
          ++s25;
          }
           if(x[i]==50)
              {sum=sum+x[i]-(x[i]-25);

              ++s50;
              --s25;
              }

          if(x[i]==100)
          {
if (s50){
              --s50;
              --s25;
} else s25-=3;
              sum=sum+x[i]-(x[i]-25);
          }
          }
         }

     if(counter==n&&s25>=0&&s50>=0)
     {
        cout<<"YES"<<endl;
     }
     else
     {
         cout<<"NO"<<endl;
     }
}