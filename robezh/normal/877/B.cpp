#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int llst[5005];
int rlst[5005];

int main(){
	string a;
	getline(cin,a);
	int len = a.length();
	for(int i = 0; i < len; i++){
		llst[i] = 1;
		rlst[i] = 1;
	}
	llst[0] = 1;
	rlst[len-1] = 1;
	for(int i = 1; i < len; i++){
		for(int j = 0; j < i; j++){
			if(a[i] >= a[j]){
				llst[i] = max(llst[i], llst[j] + 1);
			}
		}
	}
	for(int i = len-2; i >= 0; i--){
		for(int j = len-1; j > i; j--){
			if(a[i] >= a[j]){
				rlst[i] = max(rlst[i], rlst[j] + 1);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < len; i++){
		ans = max(ans, rlst[i] + llst[i] - 1);
	}
	cout<<ans;
	
	
}