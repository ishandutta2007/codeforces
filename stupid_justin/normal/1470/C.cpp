#include<bits/stdc++.h>
using namespace std;
unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
int n,k,x,v;void Q(int t){x=t;cout<<"? "<<x+1<<endl;cin>>v;}
int main(){cin>>n>>k;v=k;while(v==k)Q(rnd()%n);while(v!=k)Q((x+(v<k?1:n-1))%n);cout<<"! "<<x+1<<endl;}