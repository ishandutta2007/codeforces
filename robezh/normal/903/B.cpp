#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> res;

int main(){
	int h1,a1,c1;
	int h2,a2;
	
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	while(h2 > 0){
		if(h1 > a2 || a1 >= h2){
			res.push_back("STRIKE");
			h2 -= a1;
			h1 -= a2;
		}
		else{
			res.push_back("HEAL");
			h1 -= a2;
			h1 += c1;
		}
	}
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	
}