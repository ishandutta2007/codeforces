#include <bits/stdc++.h>
using namespace std;

int cnt1,cnt4,cnt2,cnt3;

int main(){
	ios::sync_with_stdio(0);
	cin>>cnt1>>cnt2>>cnt3>>cnt4;
	if(!cnt1&&!cnt4&&cnt3){
		puts("0");
		return 0;
	}
	putchar((cnt1==cnt4)+'0');
	return 0; 
}