//https://codeforces.com/problemset/problem/507/B
#include<bits/stdc++.h>
using namespace std;
 long long int isq(long long int n){
    if(n==1||n==0) return n;
  long long  int u=n/2,l=1,mid;
    while(l<=u){
    mid=(l+u)/2;
 long long unsigned int t=mid*mid;
      if(t==n) return mid;
      else if(t>n) {
          u=mid-1;
      }
      else l=mid+1;
  }
  return -1;

}
int main(){
    int r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
  long long int d;
    d = (pow(x1-x2,2)+pow(y1-y2,2));

    if(isq(d)==-1)  cout<<(int)sqrt(d)/(2*r)+1<<endl;
    else if((int)sqrt(d)%(2*r)!=0) cout<<(int)sqrt(d)/(2*r)+1<<endl;
    else cout<<(int)sqrt(d)/(2*r)<<endl;
}