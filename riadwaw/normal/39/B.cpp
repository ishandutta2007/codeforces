#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int c=0;
	vector<int>v;
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		int b;
		cin>>b;
		if(b==c+1)
		{
			c++;
			v.push_back(i);
		}
	}
	cout <<c<<'\n';
	for(int i=0;i<c;i++){
		cout<<(v[i]+2000)<<' ';
	}
	return 0;
}