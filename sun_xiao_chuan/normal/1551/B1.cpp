#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string s;

int main(){
	cin>>t;
	while(t--){
		j=k=0;
		memset(a,0,sizeof(a));
		cin>>s;
		for(auto i:s){
			if(a[i]==0){j++;}
			if(a[i]==1){k++;}
			a[i]++;
		}
		cout<<(j+k)/2<<endl;
	}
}