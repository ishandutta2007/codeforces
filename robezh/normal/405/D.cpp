#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int k = 1000001;

int n;
int num[500050];
int V[1000005];
int V_size = 0;
//map<int, int> M;
bool M[1000005];

int main(){
	scanf("%d", &n);
	fill(M, M + 1000005, false);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		M[num[i]] = 1;
	} 
	
	int p = 0;
	for(int i = 0; i < n; i++){
		if(M[k - num[i]]) p++;
		else V[V_size++] = k - num[i];
	}
	p /= 2;
	for(int i = 1; i <= 1000000; i++){
		if(p == 0) break;
		if(!M[i] && !M[k-i]){
			V[V_size++] = i;
			V[V_size++] = k-i;
			p--;
		}
	}
	printf("%d\n", V_size);
	for(int i = 0; i < V_size; i++){
		printf("%d ", V[i]);
	}
}