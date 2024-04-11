#include<iostream>
#define f first
using namespace std;int R,N;pair<int,int>a,b,c;int main(){cin>>R>>N,b=make_pair(1,0),c=make_pair(R,2);for(int i=0;i<N;i++)cin>>a.f>>a.second,b=max(b,a),c=min(c,a);cout<<(c.f-1^R-b.f^c.f+b.f+c.second+b.second+N-1&1?"WIN\n":"LOSE\n");}