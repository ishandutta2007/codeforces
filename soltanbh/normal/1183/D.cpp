#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll q,x,n,e=1e6;
map<int,int> mark,mark2;
int main(){
	cin>>q;
	f(i,0,q){
		cin>>n;
		f(j,0,n){
			cin>>x;mark[x*e+i]++,mark2[(mark[x*e+i])*e+i]++,mark2[(mark[x*e+i]-1)*e+i]--;
		}
		int sum=0,t=0;
		f_(j,n,1){
			t+=mark2[j*e+i];
			if(t>0){
				t--;
				sum+=j;
			}
		}
		cout<<sum<<endl;
	}
}