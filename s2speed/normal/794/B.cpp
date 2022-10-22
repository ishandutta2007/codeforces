#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	double n , h;
	cin>>n>>h;
	double ans;
	for(double i = 1 ; i < n ; i++){
		ans = sqrt((i / n)) * h;
		printf("%.8lf " , ans);
	}
	cout<<"\n";
	return 0;
}