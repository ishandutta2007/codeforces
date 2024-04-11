#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

int n;

string solve(int x){
	string rs="";
	while (x>0){
		rs+=(x%n)+'0';
		x/=n;
	}
	reverse(rs.begin(),rs.end());
	return rs;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d",&n);

	for (int i=1; i<n; i++){
		for (int j=1; j<n; j++)
			cout<<solve(i*j)<<" ";
		cout<<endl;
	}

	return 0;
}