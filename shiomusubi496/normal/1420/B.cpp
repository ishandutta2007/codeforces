#include<bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    while(Q--){
      long long N;
      cin>>N;
      vector<int> A(40);
      for(int i=0;i<N;i++){
        int a,cnt=0;
        cin>>a;
        while(a>0)a/=2,cnt++;
        A[cnt-1]++;
      }
      long long sum=0,ans=0;
      for(int i=0;i<40;i++)
        ans+=A[i]*sum,sum+=A[i];
      cout<<N*(N-1)/2-ans<<endl;
    }
}