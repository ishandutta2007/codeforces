//https://codeforces.com/contest/450/problem/B
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int mo(long long int a){
     if(a<0) return mo((a+mod)%mod);
     else return a%mod;
}
int main(){
  long long  int x,y,n;
    cin>>x>>y>>n;
  long long  int arr[6]={x,y,y-x,-x,-y,x-y};
    long long int a= arr[(n-1)%6];
   cout<<mo(a)<<"\n";

}