#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	int a , b , c , d , e , f;
	ll counter = 0;
	cin>>a>>b>>c>>d>>e>>f;
	if(e > f){
		counter += e * min(a , d);
		d -= min(a , d);
		if(d != 0){
			counter += min(d , min(b , c)) * f;
		}
	} else {
		counter += min(d , min(b , c)) * f;
		d -= min(min(b , c) , d);
		if(d != 0){
			counter += min(a , d) * e;
		}
	}
	cout<<counter<<endl;
	return 0;
}