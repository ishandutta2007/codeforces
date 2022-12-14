//In the name of God
#include <iostream>
using namespace std;
long long hei,dest;
long long dfs(int h,int LoR){
	if(h == 0)
		return 0;
	long long bit = (((long long)1 << (h-1)) & dest) >> (h - 1);
	if((LoR && (((long long)1 << (h-1)) & dest)) || (!LoR && !(((long long)1 << (h-1)) & dest))){
		return dfs(h-1,1-bit) + 1;
	}else{
		return ((long long)1 << (h)) + dfs(h-1,1-bit);
	}
}
int main(){
	cin >> hei >> dest;
	--dest;
	cout << dfs(hei,0)<< endl;
}