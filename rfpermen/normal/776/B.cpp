#include<iostream>
#include<math.h>
#include<cstdio>
#include<string>
#include<string.h>

using namespace std;

bool prima[1000000];
int x;

int main(){
	cin>>x;
	memset(prima,true,sizeof prima);
	prima[0]=false; prima[1]=false;
	for( int i=2;i*i<= x+1;i++){
		if (prima[i]) {
			for( int j=i*i; j<=x+1; j += i) {
				prima[j]= false;
			}
		}
	}
	if (x<3) {cout << 1 << endl;}
	else {cout << 2 << endl;}
	for (int i=2;i<=x+1;i++){
		if(prima[i]) {
		cout << 1 << " ";
	} else cout << 2 << " ";
    }
    return 0;
}