#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> to[100005];
int insetone[100005];
int n;

void searchfromindex(int k, int from){
	if(k != 1) insetone[k] = 3 - insetone[from];
	else insetone[k] = 1;
	for(int i = 0; i < to[k].size(); i++){
		if(to[k][i] != from){
			searchfromindex(to[k][i], k);
		}
	}
}

int main(){
	memset(insetone, 0, sizeof(insetone));
	
	int tmpa, tmpb;
	scanf("%d", &n);
	
	for(int i = 1; i <= n-1; i++){
		scanf("%d %d", &tmpa, &tmpb);
		to[tmpa].push_back(tmpb);
		to[tmpb].push_back(tmpa);
	}
	insetone[1] = 1;
	searchfromindex(1,1000000);
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++){
		if(insetone[i] == 1){
			cnt1 ++;
		}
		else{
			cnt2 ++;
		}
	}
	cout<< (long long)cnt1*(long long)cnt2 - n + 1;
	
	return 0;
	
}