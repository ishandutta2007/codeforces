// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    srand(time(0));
    int x=rand()%10000000;
    int n,m;cin>>n>>m;
    if(m==3 && n>4) return cout<<-1<<endl,0;
    if(m==3 && n==4) return cout<<"0 0\n3 0\n0 3\n1 1\n",0;
    for(int i=0;i<m;i++) cout<<i<<" "<<x+i*i<<"\n";
    for(int i=0;i<n-m;i++) cout<<-i<<" "<<-x-i*i<<"\n";
}