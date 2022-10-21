#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int ind[200500];
int num[200500];
int cnt = 0;

map<int, int> M;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &ind[i]);
	M[0] = 0;
	num[0] = 0;
	cnt = 1;
	for(int i = 1; i <= n; i++){
		if(M[num[ind[i]]] != ind[i]){
			num[i] = cnt;
			cnt++;
			M[num[i]] = i;
		}
		else{
			M[num[ind[i]]] = i;
			num[i] = num[ind[i]];
		}
	}
	cout << cnt << endl;
}