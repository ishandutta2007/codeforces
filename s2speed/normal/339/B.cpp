#include<iostream>

using namespace std;

int main(){
	int n , m , inp , preinp = 1;
	long long counter = 0;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>inp;
		if(preinp > inp){
			counter += inp - preinp + n;
		}
		else{
			counter += inp - preinp;
		}
		preinp = inp;
	}
	cout<<counter<<endl;
	return 0;
}