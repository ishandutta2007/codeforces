#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> sqr;
vector<int> ns_move;
int n0 = 0;
int num[200050];

bool is_sq(int n){
	double sq = sqrt((double)n);
	return sq == floor(sq);
}

int main(){
	for(int i = 0; i <= 31623; i++){
		sqr.push_back(i * i);
	}
	int n;
	
	cin >> n;
	for(int i = 0 ; i < n; i++){
		scanf("%d", &num[i]);
		if(num[i] == 0) n0 ++;
		if(!is_sq(num[i])){
			int k = lower_bound(sqr.begin(), sqr.end(), num[i]) - sqr.begin();
			ns_move.push_back(min(sqr[k]-num[i], num[i]-sqr[k-1]));
			//cout << "loewr_b = " << min(sqr[k]-num[i], num[i]-sqr[k-1]) <<  endl;
		}
	}
	int ns_size = ns_move.size();
	if(ns_size == n/2) return !printf("0");
	if(ns_size > n/2){
		int diff = ns_size - n/2;
		sort(ns_move.begin(), ns_move.end());
		long long sum = 0;
		//cout << "sum";
		for(int i = 0; i < diff; i++){
			sum += ns_move[i];
		}
		cout << sum;
		return 0;
	}
	//cout << "ns_size == " << ns_size << endl;
	int nn0 = n - ns_size - n0;
	int diff = n/2 - ns_size;
	int sum = nn0 >= diff ? diff : nn0 + (diff-nn0) * 2;
	return !printf("%d",sum);
	
}