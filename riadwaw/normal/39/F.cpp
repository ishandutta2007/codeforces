#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,l,k;
	cin>>n>>l>>k;
	vector<int> lag;
	vector<int>ok;
	int lg[100];
	int min=n+1;
	for(int i=0;i<l;i++){
		int a;
		cin>>a;
		lag.push_back(a);
		lg[i]=0;
	}
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		for(int j=0;j<l;j++){
			if((a%lag[j])==0){
				lg[j]++;
			}
		}
	}
	min=n+1;
	for(int i=0;i<l;i++){
		if(lg[i]<min){
			min=lg[i];
			ok.clear();
			ok.push_back(i);
		}
		else if(lg[i]==min){
			ok.push_back(i);
		}
	}
	cout<<ok.size()<<'\n';
	for(int i=0;i<ok.size();i++){
		cout << (ok[i]+1)<<' ';
	}
	return 0;
}