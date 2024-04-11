#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
       
int a;

int sum(int n){
	int x=a,ans=0;
	while(x){
		ans+=x%n;
		x/=n; 
	}
	return ans;
}

int nod(int a,int b){
	if(a<b)
		swap(a,b);
	if(!b)
		return a;
	return nod(a%b,b);
}

int main(){
	int ans=0;
	cin>>a;
	forn(i,a-2)
		ans+=sum(i+2);  
	int no=nod(ans,a-2);
	cout<<ans/no<<"/"<<(a-2)/no;
}